#include <string.h>
#include "treeNodes.h"
#include "treeUtils.h"
#include "symbolTable.h"
#include "semantics.h"
#include "parser.tab.h"

bool globalMainFound;

extern int numErrors;
extern int numWarnings;

static int goffset = 0;
static int foffset = 0;
static int varCounter = 0;
static bool newScope = true;
static bool inLoop = false;

// Function declarations

TreeNode *loadIOLib(TreeNode *syntaxTree);
void treeTraverse(TreeNode *current, SymbolTable *symtab);

// Function definitions

TreeNode *semanticAnalysis(TreeNode *syntaxTree, SymbolTable *symtab, int &globalOffset)
{
    syntaxTree = loadIOLib(syntaxTree);
    treeTraverse(syntaxTree, symtab);
    globalOffset = goffset;
    
    return syntaxTree;
}

TreeNode *loadIOLib(TreeNode *syntaxTree)
{
    TreeNode *input, *output, *param_output;
    TreeNode *inputb, *outputb, *param_outputb;
    TreeNode *inputc, *outputc, *param_outputc;
    TreeNode *outnl;
    
    ///////// Stuff from next slides
    // link them and prefix the tree we are interested in traversing.
    // This will put the symbols in the symbol table.
    
    // Slide 2
    
    input = newDeclNode(FuncK, Integer);
    input->lineno = -1;
    input->attr.name = strdup("input"); 
    input->type = Integer; 
    
    inputb = newDeclNode(FuncK, Boolean);
    inputb->lineno = -1;
    inputb->attr.name = strdup("inputb");
    inputb->type = Boolean;
    
    inputc = newDeclNode(FuncK, Boolean);
    inputc->lineno = -1;
    inputc->attr.name = strdup("inputc");
    inputc->type = Char;
    
    param_output = newDeclNode(ParamK, Void);
    param_output->attr.name = strdup("*dummy*");
    param_output->lineno = -1;
    param_output->type = Integer;
    
    output = newDeclNode(FuncK, Void);
    output->lineno = -1;
    output->attr.name = strdup("output");
    output->child[0] = param_output;
    
    param_outputb = newDeclNode(ParamK, Void);
    param_outputb->lineno = -1;
    param_outputb->attr.name = strdup("*dummy*");
    param_outputb->type = Boolean;
    
    outputb = newDeclNode(FuncK, Void);
    outputb->child[0] = param_outputb;
    outputb->lineno = -1;
    outputb->attr.name = strdup("outputb");
    outputb->type = Void;
    
    param_outputc = newDeclNode(ParamK, Void);
    param_outputc->attr.name = strdup("*dummy*");
    param_outputc->type = Char;
    param_outputc->lineno = -1;
    
    outputc = newDeclNode(FuncK, Void);
    outputc->child[0] = param_outputc;
    outputc->type = Void;
    outputc->attr.name = strdup("outputc");
    outputc->lineno = -1;
    
    outnl = newDeclNode(FuncK, Void);
    outnl->lineno = -1;
    outnl->type = Void;
    outnl->attr.name = strdup("outnl");
    outnl->child[0] = NULL;
    
    // Slide 1
    
    input->sibling = output;
    output->sibling = inputb;
    inputb->sibling = outputb;
    outputb->sibling = inputc;
    inputc->sibling = outputc;
    outputc->sibling = outnl;
    outnl->sibling = syntaxTree;
    
    return input;
}

bool insertError(TreeNode *current, SymbolTable *symtab)
{
    if(!symtab->insert(current->attr.name, current))
    {
        //put an error message here for assignment 6
        return false;
    }
    return true;
}

void checkParameterTypes(TreeNode *current, TreeNode *declaration, SymbolTable *symtab)
{
    TreeNode *params = current->child[0];
    TreeNode *args;
    TreeNode *temp;
    
    while(params)
    {
        temp = params->sibling;
        params->sibling = NULL;
        treeTraverse(params, symtab);
        params->sibling = temp;
        params = params->sibling;
    }
 
    return;
}

void treeDeclTraverse(TreeNode *current, SymbolTable *symtab)
{
    if(current == NULL)
    {
        return;
    }

    newScope = 1;
    switch(current->kind.decl)
    {
        case VarK:
            treeTraverse(current->child[0], symtab); 
            // no break on purpose, follow through into Paramk
        case ParamK:
            if(insertError(current, symtab))
            {
                if(symtab->depth() == 1)
                {
                    current->varKind = Global;
                    current->offset = goffset;
                    goffset -= current->size;
                } 
                else if(current->isStatic)
                {
                    current->varKind = LocalStatic;
                    current->offset = goffset;
                    goffset -= current->size;
                    {
                        char *newName;
                        newName = new char[strlen(current->attr.name) + 10];
                        sprintf(newName, "%s-%d", current->attr.name, ++varCounter);
                        symtab->insertGlobal(newName, current);
                        delete [] newName;
                    }
                }
                else
                {
                    current->varKind = Local;
                    current->offset = foffset;
                    foffset -= current->size;
                }
            }
            if(current->kind.decl == ParamK)
            {
                current->varKind = Parameter;
            } 
            else if(current->isArray)
            {
                current->offset--;
            }
            break;
        case FuncK:
            if (strcmp(current->attr.name, "main") == 0 && current->child[0] == NULL)
            {
                globalMainFound = true;
            }
            foffset = -2;
            insertError(current, symtab);
            symtab->enter(current->attr.name);
            treeTraverse(current->child[0], symtab);
            current->size = foffset;
            treeTraverse(current->child[1], symtab);
            current->varKind = Global;
            symtab->leave();
            break;
    }
}

void treeStmtTraverse(TreeNode *current, SymbolTable *symtab)
{
    if(current == NULL)
    {
        return;
    }
    
    if(current->kind.stmt == CompoundK)
    {
        newScope = 1;
    }
    
    int remoffset;
    bool oldInLoop;
    
    switch(current->kind.stmt)
    {
        case CompoundK:
            //printf("CompoundK\n");
            if(newScope)
            {
                symtab->enter((char*)"CompoundStatement");
                remoffset = foffset;
                treeTraverse(current->child[0], symtab);
                current->size = foffset;
                treeTraverse(current->child[1], symtab);
                foffset = remoffset;
                symtab->leave();
            } 
            else
            {
                newScope = 1;
                treeTraverse(current->child[0], symtab);
                current->size = foffset;
                treeTraverse(current->child[1], symtab);
            }
            break;
        case ForK:
            oldInLoop = inLoop; // store for the case in which their is a loop outside of the one in which we are currently in, setting false later when restoring wouldn't account for this
            inLoop = true;
            symtab->enter((char*)"ForStatement");
            remoffset = foffset;
            treeTraverse(current->child[0], symtab);
            foffset -= 2;
            current->size = foffset;
            treeTraverse(current->child[1], symtab);
            treeTraverse(current->child[2], symtab);
            foffset = remoffset;
            symtab->leave();
            inLoop = oldInLoop;
            break;
        case WhileK:
            oldInLoop = inLoop; // store for the case in which their is a loop outside of the one in which we are currently in, setting false later when restoring wouldn't account for this
            inLoop = true;
            treeTraverse(current->child[0], symtab);
            treeTraverse(current->child[1], symtab);
            treeTraverse(current->child[2], symtab);
            
            if(current->child[0]->type != Boolean)
            {
                printf("SEMANTIC ERROR(%d): Expecting Boolean test condition in while statement but got %s.\n", current->lineno, expTypeToStr(current->child[0]->type));
                numErrors++;
            }
            if(current->child[0]->isArray)
            {
                printf("SEMANTIC ERROR(%d): Cannot use array as test condition in while statement.\n", current->lineno);
                numErrors++;
            }
            
            inLoop = oldInLoop;
            break;
        case IfK:
            treeTraverse(current->child[0], symtab);
            treeTraverse(current->child[1], symtab);
            treeTraverse(current->child[2], symtab);
            
            if(current->child[0]->type != Boolean)
            {
                printf("SEMANTIC ERROR(%d): Expecting Boolean test condition in if statement but got %s.\n", current->lineno, expTypeToStr(current->child[0]->type));
                numErrors++;
            }
            if(current->child[0]->isArray)
            {
                printf("SEMANTIC ERROR(%d): Cannot use array as test condition in if statement.\n", current->lineno);
                numErrors++;
            }
            
            break;
        case ReturnK:
            treeTraverse(current->child[0], symtab);
            treeTraverse(current->child[1], symtab);
            treeTraverse(current->child[2], symtab);
            
            if(current->child[0]->isArray)
            {
                printf("SEMANTIC ERROR(%d): Cannot return an array.\n", current->lineno);
                numErrors++;
            }
        
            break;
        case BreakK:
            treeTraverse(current->child[0], symtab);
            treeTraverse(current->child[1], symtab);
            treeTraverse(current->child[2], symtab);
        
            if (inLoop == false)
            {
                printf("SEMANTIC ERROR(%d): Cannot have a break statement outside of loop.\n", current->lineno);
                numErrors++;
            }
            
            break;
        case RangeK:
            treeTraverse(current->child[0], symtab);
            treeTraverse(current->child[1], symtab);
            treeTraverse(current->child[2], symtab);
            
            break;
    }
    newScope = 1;
}

void treeExpTraverse(TreeNode *current, SymbolTable *symtab)
{
    if(current == NULL)
    {
        return;
    }
    
    TreeNode *temp;
    
    switch(current->kind.exp)
    {
        case AssignK:
            // no break on purpose
        case OpK:
            treeTraverse(current->child[0], symtab);
            current->type = Integer;
            switch(current->attr.op)
            {
                case AND:
                case OR:
                case EQ:
                case NEQ:
                case LEQ:
                case GEQ:
                case '<':
                case '>':
                case NOT:
                    current->type = Boolean;
                    break;
                case '=':
                    /*
                    if(current->type != current->child[1]->type)
                    {
                        printf("SEMANTIC ERROR(%d): '=' requires operands of the same type but lhs is %s and rhs is %s.\n", current->lineno, expTypeToStr(current->child[0]->type),expTypeToStr(current->child[1]->type));
                        numErrors++;
                    }
                    //*/
                case '[':
                    current->type = current->child[0]->type;
                    break;
            }
            treeTraverse(current->child[1], symtab);
            break;
        case CallK:
            //printf("CallK %s\n", current->attr.name);
            temp = (TreeNode *)symtab->lookup(current->attr.name);
            if(temp != NULL)
            {
                current->type = temp->type;
                current->size = temp->size;
                checkParameterTypes(current, temp, symtab);
                
            }
            else
            {
                printf("SEMANTIC ERROR(%d): Symbol '%s' is not declared.\n", current->lineno, current->attr.name);
                numErrors++;
            }
            break;
        case IdK:
            //printf("Looking for %s\n", current->attr.name);
            temp = (TreeNode *)symtab->lookup(current->attr.name);
            if(temp != NULL)
            {
                //printf("Found\n");
                current->type = temp->type;
                current->isStatic = temp->isStatic;
                current->isArray = temp->isArray;
                current->size = temp->size;
                current->varKind = temp->varKind;
                current->offset = temp->offset; 
            }
            else
            {
                printf("SEMANTIC ERROR(%d): Symbol '%s' is not declared.\n", current->lineno, current->attr.name);
                numErrors++;
            }
            
            break;
        // NOT FINISHED
        case ConstantK:
            if(current->type == Char && current->isArray)
            {
                current->varKind = Global;
                current->offset = goffset - 1;
                goffset -= current->size;
            }
    }
    
    newScope = 1;
}

void treeTraverse(TreeNode *current, SymbolTable *symtab)
{
    if(current == NULL)
    {
        return;
    }
    
    switch(current->nodekind){
        case DeclK:
            treeDeclTraverse(current, symtab);
            break;
        case StmtK:
            treeStmtTraverse(current, symtab);
            break;
        case ExpK:
            treeExpTraverse(current, symtab);
            break;
    }
    
    if(current->sibling)
    {
        treeTraverse(current->sibling, symtab);
    }
    
}
