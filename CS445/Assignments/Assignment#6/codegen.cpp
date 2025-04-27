#include "codegen.h"
#include "emitcode.h"
#include "symbolTable.h"
#include "parser.tab.h"
#include "scanType.h"

extern int numErrors;
extern int numWarnings;
//extern void yyparse(); // changed this to int as below to match parser.y yyparse()
extern int yyparse();
extern int yydebug;
extern TreeNode *syntaxTree;
extern char **largerTokens;
extern void initTokenStrings();
// These offsets that never change
#define OFPOFF 0
#define RETURNOFFSET -1
int toffset; // next available temporary space
FILE *code; // shared global code – already included
static bool linenumFlag; // mark with line numbers
static int breakloc; // which while to break to
static SymbolTable *globals; // the global symbol table

void codegenGeneral(TreeNode *currnode); 
void codegenDecl(TreeNode *currnode);
void codegenStatement(TreeNode *currnode);
void codegenExpression(TreeNode *currnode);

void initAGlobalSymbol(std::string sym, void *ptr)
{
    TreeNode *currnode;
    
    // printf("Symbol: %s\n", sym.c_str()); // dump the symbol table
    currnode = (TreeNode *)ptr;
    // printf("lineno: %d\n", currnode->lineno); // dump the symbol table
    if (currnode->lineno != -1) {
        if (currnode->isArray) {
            emitRM((char *)"LDC", AC, currnode->size-1, 6, (char *)"load size of array", currnode->attr.name);
            emitRM((char *)"ST", AC, currnode->offset+1, GP, (char *)"save size of array", currnode->attr.name);
        }
        if (currnode->kind.decl==VarK && 
        (currnode->varKind == Global || currnode->varKind == LocalStatic)) {
            if (currnode->child[0]) {
                // compute rhs -> AC;
                codegenExpression(currnode->child[0]);
                
                // save it
                emitRM((char *)"ST", AC, currnode->offset, GP,
                (char *)"Store variable", currnode->attr.name);
            }
        }
    }
}

void initGlobalArraySizes()
{
    emitComment((char *)"INIT GLOBALS AND STATICS");
    globals->applyToAllGlobal(initAGlobalSymbol);
    emitComment((char *)"END INIT GLOBALS AND STATICS");
}

// Generate a header for our code
void codegenHeader(char *srcFile)
{
    emitComment((char *)"bC compiler version bC-Su23");
    emitComment((char *)"File compiled: ", srcFile);
}

void commentLineNum(TreeNode *currnode)
{
    char buf[16];
    if (linenumFlag) {
        sprintf(buf, "%d", currnode->lineno);
        emitComment((char *)"Line: ", buf);
    }
}

int offsetRegister(VarKind v) {
    switch (v) {
        case Local: return FP;
        case Parameter: return FP;
        case Global: return GP;
        case LocalStatic: return GP;
        default:
            printf((char *)"ERROR(codegen): looking up offset register for a variable of type %d\n", v);
            return 666;
    }
}

void codegenLibraryFun(TreeNode *currnode)
{
    emitComment((char *)"");
    emitComment((char *)"** ** ** ** ** ** ** ** ** ** ** **");
    emitComment((char *)"FUNCTION", currnode->attr.name);
    
    // remember where this function is
    currnode->offset = emitSkip(0);
    
    // Store return address
    emitRM((char *)"ST", AC, RETURNOFFSET, FP, (char *)"Store return address");
    
    // Next slides here
    // skipped slide 17 and 18 because it seems to be covered by slide 19
    if (strcmp(currnode->attr.name, (char *)"input")==0) {
        emitRO((char *)"IN", RT, RT, RT, (char *)"Grab int input");
    }
    // Dont know why you need this segment of duplicate ifs from here...
    else if (strcmp(currnode->attr.name, (char *)"input")==0) {
        emitRO((char *)"IN", RT, RT, RT, (char *)"Grab int input");
    }
    else if (strcmp(currnode->attr.name, (char *)"inputb")==0) {
        emitRO((char *)"INB", RT, RT, RT, (char *)"Grab bool input");
    }
    else if (strcmp(currnode->attr.name, (char *)"inputc")==0) {
        emitRO((char *)"INC", RT, RT, RT, (char *)"Grab char input");
    }
    else if (strcmp(currnode->attr.name, (char *)"input")==0) {
        emitRO((char *)"IN", RT, RT, RT, (char *)"Grab int input");
    }
    else if (strcmp(currnode->attr.name, (char *)"inputb")==0) {
        emitRO((char *)"INB", RT, RT, RT, (char *)"Grab bool input");
    }
    else if (strcmp(currnode->attr.name, (char *)"inputc")==0) {
        emitRO((char *)"INC", RT, RT, RT, (char *)"Grab char input");
    }
    else if (strcmp(currnode->attr.name, (char *)"output")==0) {
        emitRM((char *)"LD", AC, -2, FP, (char *)"Load parameter");
        emitRO((char *)"OUT", AC, AC, AC, (char *)"Output integer");
    }
    else if (strcmp(currnode->attr.name, (char *)"outputb")==0) {
        emitRM((char *)"LD", AC, -2, FP, (char *)"Load parameter");
        emitRO((char *)"OUTB", AC, AC, AC, (char *)"Output bool");
    }
    else if (strcmp(currnode->attr.name, (char *)"outputc")==0) {
        emitRM((char *)"LD", AC, -2, FP, (char *)"Load parameter");
        emitRO((char *)"OUTC", AC, AC, AC, (char *)"Output char");
    }
    // to here with (ifs above are repeated again below) - this is for sure correct though
    else if (strcmp(currnode->attr.name, (char *)"inputb")==0) {
        emitRO((char *)"INB", RT, RT, RT, (char *)"Grab bool input");
    }
    else if (strcmp(currnode->attr.name, (char *)"inputc")==0) {
        emitRO((char *)"INC", RT, RT, RT, (char *)"Grab char input");
    }
    else if (strcmp(currnode->attr.name, (char *)"output")==0) {
        emitRM((char *)"LD", AC, -2, FP, (char *)"Load parameter");
        emitRO((char *)"OUT", AC, AC, AC, (char *)"Output integer");
    }
    else if (strcmp(currnode->attr.name, (char *)"outputb")==0) {
        emitRM((char *)"LD", AC, -2, FP, (char *)"Load parameter");
        emitRO((char *)"OUTB", AC, AC, AC, (char *)"Output bool");
    }
    else if (strcmp(currnode->attr.name, (char *)"outputc")==0) {
        emitRM((char *)"LD", AC, -2, FP, (char *)"Load parameter");
        emitRO((char *)"OUTC", AC, AC, AC, (char *)"Output char");
    }
    else if (strcmp(currnode->attr.name, (char *)"outnl")==0) {
        emitRO((char *)"OUTNL", AC, AC, AC, (char *)"Output a newline");
    }
    else {
        emitComment((char *)"ERROR(LINKER): No support for special function");
        emitComment(currnode->attr.name);
    }
    
    emitRM((char *)"LD", AC, RETURNOFFSET, FP, (char *)"Load return address");
    emitRM((char *)"LD", FP, OFPOFF, FP, (char *)"Adjust fp");
    emitGoto(0, AC, (char *)"Return");
    
    emitComment((char *)"END FUNCTION", currnode->attr.name);
    
}

// process functions
void codegenFun(TreeNode *currnode)
{
    emitComment((char *)"");
    emitComment((char *)"** ** ** ** ** ** ** ** ** ** ** **");
    emitComment((char *)"FUNCTION", currnode->attr.name);
    toffset = currnode->size; // recover the end of activation record
    emitComment((char *)"TOFF set:", toffset);
    
    // IMPORTANT: For function nodes the offset is defined to be the position of the
    // function in the code space! This is accessible via the symbol table.
    // remember where this function is:
    currnode->offset = emitSkip(0); // offset holds the instruction address!!
    
    // Store return address
    emitRM((char *)"ST", AC, RETURNOFFSET, FP, (char *)"Store return address");

    // Generate code for the statements...
    codegenGeneral(currnode->child[1]);
    
    // In case there was no return statement
    // set return register to 0 and return
    emitComment((char *)"Add standard closing in case there is no return statement");
    emitRM((char *)"LDC", RT, 0, 6, (char *)"Set return value to 0");
    emitRM((char *)"LD", AC, RETURNOFFSET, FP, (char *)"Load return address");
    emitRM((char *)"LD", FP, OFPOFF, FP, (char *)"Adjust fp");
    emitGoto(0, AC, (char *)"Return");
    
    emitComment((char *)"END FUNCTION", currnode->attr.name);
}

// Generate init code ...
void codegenInit(int initJump, int globalOffset)
{
    backPatchAJumpToHere(initJump, (char *)"Jump to init [backpatch]");
    
    emitComment((char *)"INIT");
    //OLD pre 4.6 TM emitRM((char *)"LD", GP, 0, 0, (char *)"Set the global pointer");
    emitRM((char *)"LDA", FP, globalOffset, GP, (char *)"set first frame at end of globals");
    emitRM((char *)"ST", FP, 0, FP, (char *)"store old fp (point to self)");
    
    initGlobalArraySizes();
    
    emitRM((char *)"LDA", AC, 1, PC, (char *)"Return address in ac");
    { 
        // jump to main
        TreeNode *funcNode;
        
        funcNode = (TreeNode *)(globals->lookup((char *)"main"));
        if (funcNode) {
            emitGotoAbs(funcNode->offset, (char *)"Jump to main");
        }
        else {
            printf((char *)"ERROR(LINKER): Procedure main is not defined.\n");
            //numErrors++;
        }
    }
    
    emitRO((char *)"HALT", 0, 0, 0, (char *)"DONE!");
    emitComment((char *)"END INIT");
}

void codegenDecl(TreeNode *currnode)
{
    commentLineNum(currnode);
    switch(currnode->kind.decl) {
        case VarK:
            // You have a LOT to do here!!!!!
            if (currnode->isArray) {
                switch (currnode->varKind) {
                    case Local:
                        emitRM((char *)"LDC", AC, currnode->size-1, 6, (char *)"load size of array", currnode->attr.name);
                        emitRM((char *)"ST", AC, currnode->offset+1, offsetRegister(currnode->varKind), 
                        (char *)"save size of array", currnode->attr.name);
                        break;
                    case LocalStatic:
                    case Parameter:
                    case Global:
                        // do nothing here
                        break;
                    case None:
                        // Error Condition
                        if(1){
                            printf("AssignK isArray true Varkind None Error\n");
                        }
                        break;
                }
                // ARRAY VALUE initialization
                if (currnode->child[0]) {
                    codegenExpression(currnode->child[0]);
                    emitRM((char *)"LDA", AC1, currnode->offset, offsetRegister(currnode->varKind), (char *)"address of lhs");
                    emitRM((char *)"LD", AC2, 1, AC, (char *)"size of rhs");
                    emitRM((char *)"LD", AC3, 1, AC1, (char *)"size of lhs");
                    emitRO((char *)"SWP", AC2, AC3, 6, (char *)"pick smallest size");
                    emitRO((char *)"MOV", AC1, AC, AC2, (char *)"array op =");
                }
            }
            else
            {
                // !currnode->isArray
                // SCALAR VALUE initialization
                if (currnode->child[0]) {
                    switch (currnode->varKind) {
                        case Local:
                            // compute rhs -> AC;
                            codegenExpression(currnode->child[0]);
                            
                            // save it
                            emitRM((char *)"ST", AC, currnode->offset, FP, (char *)"Store variable", currnode->attr.name);
                        case LocalStatic:
                        case Parameter:
                        case Global:
                            // do nothing here
                            break;
                        case None:
                            ///Error condition!!!
                            if(1){
                                printf("AssignK isArray false Varkind None Error\n");
                            }
                            break;
                    }
                }
            }
            break;
        case FuncK:
            if (currnode->lineno == -1) { // These are the library functions we just added
                codegenLibraryFun(currnode);
            }
            else {
                codegenFun(currnode);
            }
            break;
        case ParamK:
            // IMPORTANT: no instructions need to be allocated for parameters here
            break;
    }
}

void codegenStatement(TreeNode *currnode)
{
    // local state to remember stuff
    int skiploc=0, skiploc2=0, currloc=0; // some temporary instuction addresses
    TreeNode *loopindex=NULL; // a pointer to the index variable declaration node
    commentLineNum(currnode);

    switch (currnode->kind.stmt) {
        /////////////////Other cases
        /*
        case IfK:
            // finish
            // FIX?????
            emitComment((char *)"IF");
            codegenGeneral(currnode->child[0]);
            ///*
            if(currnode->child[0])
            {
                emitComment((char *)"THEN");
                codegenGeneral(currnode->child[1]);
                if(currnode->child[2]) // else present in if statement
                {
                    skiploc2 = emitSkip(2);
                    //printf("emitWhereAmI = %d\n", emitSkip(0));
                    //printf("Skiploc = %d\n", skiploc2);
                    backPatchAJumpToHere((char *)"JZR", AC, skiploc2, (char *)"Jump around the THEN if false [backpatch]");
                    emitComment((char *)"ELSE");
                    codegenGeneral(currnode->child[2]);
                    backPatchAJumpToHere(skiploc2 + 1, (char *)"Jump around the ELSE [backpatch]");
                }
                else // no else present in if statement
                {
                    skiploc = emitSkip(1);
                    backPatchAJumpToHere((char *)"JZR", AC, skiploc, (char *)"Jump around the THEN if false [backpatch]");
                }
            }
            emitComment((char *)"END IF");
            break;
        */
        case IfK:
            // finish
            // FIX?????
            emitComment((char *)"IF");
            codegenExpression(currnode->child[0]);
            ///*
            skiploc = emitSkip(1); /////////////////////////////////////////////////////
            //if(currnode->child[0]) ///////////////////////
            //{ //////////////////////////////////////////
                emitComment((char *)"THEN");
                codegenGeneral(currnode->child[1]);
                if(currnode->child[2]) // else present in if statement
                {
                    skiploc2 = emitSkip(1); //////////////////////////////
                    //printf("emitWhereAmI = %d\n", emitSkip(0));
                    //printf("Skiploc = %d\n", skiploc2);
                    backPatchAJumpToHere((char *)"JZR", AC, skiploc, (char *)"Jump around the THEN if false [backpatch]");////////////////////
                    emitComment((char *)"ELSE");
                    codegenGeneral(currnode->child[2]);
                    backPatchAJumpToHere(skiploc2, (char *)"Jump around the ELSE [backpatch]"); //////////////////////
                }
                else // no else present in if statement
                {
                //    skiploc = emitSkip(1);
                    backPatchAJumpToHere((char *)"JZR", AC, skiploc, (char *)"Jump around the THEN if false [backpatch]"); /////////////////////
                }
            //}//////////////////////////////////////////////////
            emitComment((char *)"END IF");
            break;
        case WhileK:
            emitComment((char *)"WHILE");
            currloc = emitSkip(0); // return to here to do the test
            codegenExpression(currnode->child[0]); // test expression
            
            emitRM((char *)"JNZ", AC, 1, PC, (char *)"Jump to while part");
            emitComment((char *)"DO");
            
            skiploc = breakloc; // save the old break statement return point
            breakloc = emitSkip(1); // addr of instr that jumps to end of loop
                                    // this is also the backpatch point
            
            codegenGeneral(currnode->child[1]); // do body of loop
            emitGotoAbs(currloc, (char *)"go to beginning of loop");
            backPatchAJumpToHere(breakloc, (char *)"Jump past loop [backpatch]"); 
                                            // backpatch jump to end of loop
            
            breakloc = skiploc; // restore for break statement
            emitComment((char *)"END WHILE");
            
            break;
        case ForK:
            // finish
            int savedToffset;
            int startoff, stopoff, stepoff;
            savedToffset = toffset;
            toffset = currnode->size;
            emitComment((char *)"TOFF set:", toffset);
            emitComment((char *)"FOR");
            loopindex = currnode->child[0];
            startoff = loopindex->offset;
            stopoff = startoff - 1;
            stepoff = startoff - 2;
            TreeNode *rangenode;
            rangenode = currnode->child[1];
            
            // process the RangeK inside the ForK
            //codegenGeneral(rangenode); 
            
            codegenExpression(rangenode->child[0]);
            emitRM((char *)"ST", AC, startoff, FP, (char *)"save starting value in index variable");
            codegenExpression(rangenode->child[1]);
            emitRM((char *)"ST", AC, stopoff, FP, (char *)"save stop value");
            if (rangenode->child[2]==NULL) {
                emitRM((char *)"LDC", AC, 1, 6, (char *)"default increment by 1");
            }
            else {
                codegenExpression(rangenode->child[2]);
            }
            emitRM((char *)"ST", AC, stepoff, FP, (char *)"save step value");
            
            currloc = emitSkip(0); // return to here to do the test
            
            // RangeK processing complete
            
            emitRM((char *)"LD", AC1, startoff, FP, (char *)"loop index");
            emitRM((char *)"LD", AC2, stopoff, FP, (char *)"stop value");
            emitRM((char *)"LD", AC, stepoff, FP, (char *)"step value");
            emitRO((char *)"SLT", AC, AC1, AC2, (char *)"Op <");
            emitRM((char *)"JNZ", AC, 1, PC, (char *)"Jump to loop body");
            
            skiploc = breakloc;
            breakloc = emitSkip(1);
            
            codegenGeneral(currnode->child[2]);
            
            emitComment((char *)"Bottom of loop increment and jump");
            
            emitRM((char *)"LD", AC, startoff, FP, (char *)"Load index");
            emitRM((char *)"LD", AC2, stepoff, FP, (char *)"Load step");
            emitRO((char *)"ADD", AC, AC, AC2, (char *)"increment");
            emitRM((char *)"ST", AC, startoff, FP, (char *)"store back to index");
            
            emitGotoAbs(currloc, (char *)"go to beginning of loop");
            backPatchAJumpToHere(breakloc, (char *)"Jump past loop [backpatch]"); // backpatch jump to end of loop             
            
            breakloc = skiploc; // restore for break statement
            
            emitComment((char *)"END LOOP");
            
            //toffset = savedToffset;
            
            break;
        case CompoundK:
            {
                int savedToffset;
                savedToffset = toffset; 
                toffset = currnode->size; // recover the end of activation record
                emitComment((char *)"COMPOUND");
                emitComment((char *)"TOFF set:", toffset);
                codegenGeneral(currnode->child[0]); // process inits
                emitComment((char *)"Compound Body");
                codegenGeneral(currnode->child[1]); // process body
                toffset = savedToffset; 
                emitComment((char *)"TOFF set:", toffset);
                emitComment((char *)"END COMPOUND");
            }
            break;
        case ReturnK:
            // finish
            emitComment((char *)"RETURN");
            if(currnode->child[0])
            {
                codegenExpression(currnode->child[0]);
                emitRM((char *)"LDA", RT, GP, AC, (char *)"Copy result to return register");
            }
            emitRM((char *)"LD", AC, RETURNOFFSET, FP, (char *)"Load return address");
            emitRM((char *)"LD", FP, OFPOFF, FP, (char *)"Adjust fp");
            emitGoto(0, AC, (char *)"Return");
            break;
        case BreakK:
            // finish
            emitComment((char *)"BREAK");
            emitGotoAbs(breakloc, (char *)"break");
            break;
        /*
        // case RangeK is not needed as a seperate case
        case RangeK:
            // finish
            //emitComment((char *)"RANGE");
            printf("HIT: %d\n", currnode->attr.value);
            if(currnode->child[0] == NULL) printf("NULL\n");
            if(currnode->child[1] == NULL) printf("NULL\n");
            if(currnode->child[2] == NULL) printf("NULL\n");
            codegenExpression(currnode->child[0]);
            codegenExpression(currnode->child[1]);
            // FOR SOME REASON CHILD 2 IS CURRENTLY NULL
            if(currnode->child[2] != NULL)
            {
                codegenExpression(currnode->child[2]);
            }
            //codegenExpression(currnode->child[2]);
            /*
            if(currnode->child[0])
            {
                emitRM((char *)"LDC", AC, int(currnode->child[0]->attr.value), 6, (char *)"Load integer constant");
            }
             if(currnode->child[1])
            {
                emitRM((char *)"LDC", AC, int(currnode->child[0]->attr.value), 6, (char *)"Load integer constant");
            }
             if(currnode->child[2])
            {
                emitRM((char *)"LDC", AC, int(currnode->child[0]->attr.value), 6, (char *)"Load integer constant");
            }
            //*
            break;
        //*/
        default:
            break;
    }
}

void codegenExpression(TreeNode *currnode)
{
    TreeNode *lhs = currnode->child[0];
    TreeNode *rhs = currnode->child[1];
    TreeNode *index;
    TreeNode *var;
    
    commentLineNum(currnode);
    
    //printf("\nDebug: Expression reached reached\n");
    
    switch(currnode->kind.exp){
        case AssignK:
            // 
            if (currnode->child[0]->attr.op == '[') {
                // stuff
                ///*
                index = lhs->child[1];
                var = lhs->child[0];
                int offReg;
                //offReg = offsetRegister(currnode->child[0]->varKind);
                codegenExpression(index);
                if(rhs) // if right hands  - should be the array index
                {
                    emitRM((char *)"ST", AC, toffset, FP, (char *)"Push index");
                    toffset--; 
                    emitComment((char *)"TOFF dec:", toffset);
                    codegenExpression(currnode->child[1]);
                    toffset++; 
                    emitComment((char *)"TOFF inc:", toffset);
                    emitRM((char *)"LD", AC1, toffset, FP, (char *)"Pop index");
                }
                switch(var->varKind)
                {
                    case Local:
                        emitRM((char *)"LDA", AC2, var->offset, FP, (char *)"Load address of base of array", var->attr.name);
                        break;
                    case LocalStatic:
                        //emitRM((char *)"LDA", AC2, var->offset, GP, (char *)"Load address of base of array", var->attr.name);
                        // line above not necessary because it is covered in case: Global
                        // no break
                    case Global:
                        emitRM((char *)"LDA", AC2, var->offset, GP, (char *)"Load address of base of array", var->attr.name);
                        break;
                    case Parameter:
                        emitRM((char *)"LD", AC2, var->offset, FP, (char *)"Load address of base of array", var->attr.name);
                        break;
                }
                if(rhs){
                    emitRO((char *)"SUB", AC2, AC2, AC1, (char *)"Compute offset of value");
                }
                else
                {
                    emitRO((char *)"SUB", AC2, AC2, AC, (char *)"Compute offset of value");
                }
                switch(currnode->attr.op){
                    case '=':
                        emitRM((char *)"ST", AC, 0, AC2, (char *)"Store variable", var->attr.name); // check?
                        break;
                    case ADDASS:
                        emitRM((char *)"LD", AC1, 0, AC2, 
                            (char *)"load lhs variable", var->attr.name);
                        emitRO((char *)"ADD", AC, AC1, AC, (char *)"op +=");
                        emitRM((char *)"ST", AC, 0, AC2,
                            (char *)"Store variable", var->attr.name);
                        break;
                    case SUBASS:
                        emitRM((char *)"LD", AC1, 0, AC2, 
                            (char *)"load lhs variable", var->attr.name);
                        emitRO((char *)"SUB", AC, AC1, AC, (char *)"op -=");
                        emitRM((char *)"ST", AC, 0, AC2,
                            (char *)"Store variable", var->attr.name);
                        break;
                    case MULASS:
                        emitRM((char *)"LD", AC1, 0, AC2, 
                            (char *)"load lhs variable", var->attr.name);
                        emitRO((char *)"MUL", AC, AC1, AC, (char *)"op *=");
                        emitRM((char *)"ST", AC, 0, AC2,
                            (char *)"Store variable", var->attr.name);
                        break;
                    case DIVASS:
                        emitRM((char *)"LD", AC1, 0, AC2, 
                            (char *)"load lhs variable", var->attr.name);
                        emitRO((char *)"DIV", AC, AC1, AC, (char *)"op /=");
                        emitRM((char *)"ST", AC, 0, AC2,
                            (char *)"Store variable", var->attr.name);
                        break;
                    case INC:
                        emitRM((char *)"LD", AC, 0, AC2, 
                            (char *)"load lhs variable", var->attr.name);
                        emitRM((char *)"LDA", AC, 1, AC, (char *)"increment value of", var->attr.name);
                        emitRM((char *)"ST", AC, 0, AC2,
                            (char *)"Store variable", var->attr.name);
                        break;
                    case DEC:
                        emitRM((char *)"LD", AC, 0, AC2, 
                            (char *)"load lhs variable", var->attr.name);
                        emitRM((char *)"LDA", AC, -1, AC, (char *)"decrement value of", var->attr.name);
                        emitRM((char *)"ST", AC, 0, AC2,
                            (char *)"Store variable", var->attr.name);
                        break;
                }
                //*/
            }
            else
            {
                
                int offReg;
                offReg = offsetRegister(currnode->child[0]->varKind);
                
                if(rhs){
                    codegenExpression(rhs);
                }
                
                // Lots of cases that use it. Here is a sample:
                switch(currnode->attr.op){
                    case '=':
                        emitRM((char *)"ST", AC, lhs->offset, offReg, (char *)"Store variable", lhs->attr.name); // check?
                        break;
                    case ADDASS:
                        emitRM((char *)"LD", AC1, lhs->offset, offReg, 
                            (char *)"load lhs variable", lhs->attr.name);
                        emitRO((char *)"ADD", AC, AC1, AC, (char *)"op +=");
                        emitRM((char *)"ST", AC, lhs->offset, offReg,
                            (char *)"Store variable", lhs->attr.name);
                        break;
                    case SUBASS:
                        emitRM((char *)"LD", AC1, lhs->offset, offReg, 
                            (char *)"load lhs variable", lhs->attr.name);
                        emitRO((char *)"SUB", AC, AC1, AC, (char *)"op -=");
                        emitRM((char *)"ST", AC, lhs->offset, offReg,
                            (char *)"Store variable", lhs->attr.name);
                        break;
                    case MULASS:
                        emitRM((char *)"LD", AC1, lhs->offset, offReg, 
                            (char *)"load lhs variable", lhs->attr.name);
                        emitRO((char *)"MUL", AC, AC1, AC, (char *)"op *=");
                        emitRM((char *)"ST", AC, lhs->offset, offReg,
                            (char *)"Store variable", lhs->attr.name);
                        break;
                    case DIVASS:
                        emitRM((char *)"LD", AC1, lhs->offset, offReg, 
                            (char *)"load lhs variable", lhs->attr.name);
                        emitRO((char *)"DIV", AC, AC1, AC, (char *)"op /=");
                        emitRM((char *)"ST", AC, lhs->offset, offReg,
                            (char *)"Store variable", lhs->attr.name);
                        break;
                    case INC:
                        emitRM((char *)"LD", AC, lhs->offset, offReg, 
                            (char *)"load lhs variable", lhs->attr.name);
                        emitRM((char *)"LDA", AC, 1, AC, (char *)"increment value of", lhs->attr.name);
                        emitRM((char *)"ST", AC, lhs->offset, offReg,
                            (char *)"Store variable", lhs->attr.name);
                        break;
                    case DEC:
                        emitRM((char *)"LD", AC, lhs->offset, offReg, 
                            (char *)"load lhs variable", lhs->attr.name);
                        emitRM((char *)"LDA", AC, -1, AC, (char *)"decrement value of", lhs->attr.name);
                        emitRM((char *)"ST", AC, lhs->offset, offReg,
                            (char *)"Store variable", lhs->attr.name);
                        break;
                }
            }
            break;
        case CallK:
            // finish
            
            TreeNode *funcNode;
            int callLoc;
            int savedToffset;
            //int ghostframe;
            
            funcNode = ((TreeNode *)(globals->lookup(currnode->attr.name)));
            callLoc = funcNode->offset;
            savedToffset = toffset;
            
            emitComment((char *)"CALL", currnode->attr.name);
            //ghostframe = toffset;
            emitRM((char *)"ST", FP, toffset, FP, (char *)"Store fp in ghost frame for", currnode->attr.name);
            toffset--; 
            emitComment((char *)"TOFF dec:", toffset);
            toffset--; 
            emitComment((char *)"TOFF dec:", toffset);
            
            if(currnode->child[0])
            {
                //printf("Process Parameters\n");
                int i;
                TreeNode *temp;
                temp = currnode->child[0];
                i = 1;
                
                //printf("currnode->child[0]: %d\n", currnode->child[0]->attr.name);
                while(temp)
                {
                    emitComment((char *)"Param", i);
                    codegenExpression(temp);
                    emitRM((char *)"ST", AC, toffset, FP, (char *)"Push parameter");
                    toffset--;
                    emitComment((char *)"TOFF dec:", toffset);
                    
                    if(temp->sibling)
                    {
                        temp = temp->sibling;
                        i++;
                    }
                    else
                    {
                        temp = NULL;
                    }
                }
            }
            
            emitComment((char *)"Param end", currnode->attr.name);
            
            emitRM((char *)"LDA", FP, savedToffset, FP, (char *)"Ghost frame becomes new active frame");
            emitRM((char *)"LDA", AC, FP, PC, (char *)"Return address in ac");
            emitRMAbs((char *)"JMP", PC, callLoc, (char *)"CALL", currnode->attr.name);
            emitRM((char *)"LDA", AC, GP, RT, (char *)"Save the result in ac");
            
            emitComment((char *)"Call end", currnode->attr.name);
            
            toffset = savedToffset;
            emitComment((char *)"TOFF set:", toffset);
            
            break;
        case ConstantK:
            //printf("\nDebug: ConstantK reached\n");
            switch(currnode->type){
                case Integer:
                    //printf("\nDebug: ConstantK Integer reached\n");
                    emitRM((char *)"LDC", AC, int(currnode->attr.value), 6, (char *)"Load integer constant");
                    break;
                case Boolean:
                    emitRM((char *)"LDC", AC, int(currnode->attr.value), 6, (char *)"Load Boolean constant");
                    break;
                case Char:
                    if (currnode->isArray) {
                        emitStrLit(currnode->offset, currnode->attr.string); 
                        emitRM((char *)"LDA", AC, currnode->offset, 0, (char *)"Load address of char array");
                    }
                    else 
                    {
                        emitRM((char *)"LDC", AC, int(currnode->attr.cvalue), 6, (char *)"Load char constant");
                    }
                    break;
                case Void:
                    break;
            }
            break;
        case IdK:
            // finish
            int offReg;
            offReg = offsetRegister(currnode->varKind);
            if(currnode->isArray){
                if(currnode->varKind == Parameter){
                    emitRM((char *)"LD", AC, currnode->offset, offReg, (char *)"Load address of base of array", currnode->attr.name);
                }
                else
                {
                    emitRM((char *)"LDA", AC, currnode->offset, offReg, (char *)"Load address of base of array", currnode->attr.name);
                }
            }
            else
            {
                if(currnode->child[0] == NULL){
                    emitRM((char *)"LD", AC, currnode->offset, offReg, (char *)"Load variable", currnode->attr.name);
                }
            }
            //emitRM((char *)"LD", AC, currnode->offset, FP, (char *)"Load variable", currnode->attr.name);
            break;
        case OpK:
            codegenExpression(currnode->child[0]);
            if (currnode->child[1]) {
                emitRM((char *)"ST", AC, toffset, FP, (char *)"Push left side");
                toffset--; 
                emitComment((char *)"TOFF dec:", toffset);
                codegenExpression(currnode->child[1]);
                toffset++; 
                emitComment((char *)"TOFF inc:", toffset);
                emitRM((char *)"LD", AC1, toffset, FP, (char *)"Pop left into ac1");
            }
            switch(currnode->attr.op){
                case '+':
                    emitRO((char *)"ADD", AC, AC1, AC, (char *)"Op +");
                    break;
                case '-':
                    emitRO((char *)"SUB", AC, AC1, AC, (char *)"Op -");
                    break;
                case '*':
                    emitRO((char *)"MUL", AC, AC1, AC, (char *)"Op *");
                    break;
                case '/':
                    emitRO((char *)"DIV", AC, AC1, AC, (char *)"Op /");
                    break;
                case '%':
                    emitRO((char *)"MOD", AC, AC1, AC, (char *)"Op %");
                    break;
                case '?':
                    emitRO((char *)"RND", AC, AC, 6, (char *)"Op ?");
                    break;
                case '>':
                    //printf("Reached >\n");
                    emitRO((char *)"TGT", AC, AC1, AC, (char *)"Op >");
                    break;
                case '<':
                    //printf("Reached <\n");
                    emitRO((char *)"TLT", AC, AC1, AC, (char *)"Op <");
                    break;
                case GEQ:
                    //printf("Reached >=\n");
                    emitRO((char *)"TGE", AC, AC1, AC, (char *)"Op >=");
                    break;
                case LEQ:
                    //printf("Reached <=\n");
                    emitRO((char *)"TLE", AC, AC1, AC, (char *)"Op <=");
                    break;
                case EQ:
                    //printf("Reached ==\n");
                    emitRO((char *)"TEQ", AC, AC1, AC, (char *)"Op ==");
                    break;
                case NEQ:
                    //printf("Reached !=\n");
                    emitRO((char *)"TNE", AC, AC1, AC, (char *)"Op !=");
                    break;
                case NOT:
                    emitRM((char *)"LDC", AC1, 1, 6, (char *)"Load 1");
                    emitRO((char *)"XOR", AC, AC, AC1, (char *)"Op XOR to get logical not");
                    break;
                case AND:
                    emitRO((char *)"AND", AC, AC1, AC, (char *)"Op AND");
                    break;
                case OR:
                    emitRO((char *)"OR", AC, AC1, AC, (char *)"Op OR");
                    break;
                case '[':
                    emitRO((char *)"SUB", AC, AC1, AC, (char *)"compute location from index");
                    emitRM((char *)"LD", AC, 0, AC, (char *)"Load array element");
                    break;
                case MIN:
                    //printf("Reached MIN\n");
                    emitRO((char *)"SWP", AC, AC1, AC, (char *)"Op :<:");
                    break;
                case MAX:
                    //printf("Reached MAX\n");
                    emitRO((char *)"SWP", AC1, AC, AC, (char *)"Op :>:");
                    break;
                case SIZEOF:
                    emitRM((char *)"LD", AC, FP, AC, (char *)"Load array size");
                    break;
                case CHSIGN:
                    emitRO((char *)"NEG", AC, AC, AC, (char *)"Op unary -");
                    break;
            }
            //break; // do I want a break here?
    }
}

void codegenGeneral(TreeNode *currnode)
{
    while (currnode) {
        switch (currnode->nodekind) {
            case DeclK:
                codegenDecl(currnode);
                break;
            case StmtK:
                codegenStatement(currnode);
                break;
            case ExpK:
                emitComment((char *)"EXPRESSION");
                codegenExpression(currnode);
                break;
        }
        currnode = currnode->sibling;
    }
}

// this is the top level code generator call
void codegen(FILE *codeIn, // where the code should be written
    char *srcFile, // name of file compiled
    TreeNode *syntaxTree, // tree to process
    SymbolTable *globalsIn, // globals so function info can be found
    int globalOffset,
    bool linenumFlagIn)
{
    int initJump;
    
    code = codeIn;
    globals = globalsIn;
    linenumFlag = linenumFlagIn;
    breakloc = 0;
    
    initJump = emitSkip(1); // save a place for the jump to init
    codegenHeader(srcFile); // nice comments describing what is compiled
    codegenGeneral(syntaxTree); // general code generation including I/O library
    codegenInit(initJump, globalOffset); // generation of initialization for run
}