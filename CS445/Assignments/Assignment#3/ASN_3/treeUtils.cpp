#include "treeUtils.h"
#include <string.h>

TreeNode *newDeclNode(DeclKind kind, ExpType type, TokenData *token, TreeNode *c0, TreeNode *c1, TreeNode *c2)
{
   TreeNode *newNode = new TreeNode;
   return newNode;
}

TreeNode *newStmtNode(StmtKind kind, TokenData *token, TreeNode *c0, TreeNode *c1, TreeNode *c2)
{
   TreeNode *newNode = new TreeNode;
   return newNode;
}

TreeNode *newExpNode(ExpKind kind, TokenData *token, TreeNode *c0, TreeNode *c1, TreeNode *c2)
{
   TreeNode *newNode = new TreeNode;
   return newNode;
}

static void printSpaces(FILE *listing, int depth)
{
    for (int i=0; i<depth; i++) fprintf(listing, ".   ");
}

void printTreeNode(FILE *listing,
                   TreeNode *tree,
                   bool showExpType,
                   bool showAllocation)
{
   fprintf(listing, "I am a node");
}


void printTreeRec(FILE *listing, int depth, int siblingCnt, TreeNode *tree, bool showExpType, bool showAllocation)
{
   int childCnt;
   if (tree!=NULL) {
      // print self
      printTreeNode(listing, tree, showExpType, showAllocation);
      fprintf(listing, "\n");

      // print children
      for (childCnt = 0; childCnt<MAXCHILDREN; childCnt++) {
         if (tree->child[childCnt]) {
            printSpaces(listing, depth);
            fprintf(listing, "Child: %d  ", childCnt);
            printTreeRec(listing, depth+1, 1, tree->child[childCnt], showExpType, showAllocation);
         }
      }
   }
   // print sibling
   tree = tree->sibling;
   if (tree!=NULL) {
      if (depth) {
         printSpaces(listing, depth-1);
         fprintf(listing, "Sibling: %d  ", siblingCnt);
      }
      printTreeRec(listing, depth, siblingCnt+1, tree, showExpType, showAllocation);
   }
   fflush(listing);
}

void printTree(FILE *listing, TreeNode *tree, bool showExpType, bool showAllocation)
{
   if(tree == NULL){
      printf("NULL tree");
      return;
   }
   printTreeRec(listing, 1, 1, tree, showExpType, showAllocation);
}


