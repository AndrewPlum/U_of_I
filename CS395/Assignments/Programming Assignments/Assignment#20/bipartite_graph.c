/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using an insertion sort
 * algorithm. 
 *********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_BOARD 1000
#define BCEMPTY -1

// Prototypes

void printM(int M[][2], int start, int end);
void printQueue(int Queue[], int start, int end);
void printGraph(int G[MAX_BOARD][MAX_BOARD], int Vverticies);

void enqueue(int Q[MAX_BOARD], int val, int* qStart, int* qEnd);
void dequeue(int Q[MAX_BOARD], int* qStart, int* qEnd);
int top(int Q[MAX_BOARD], int* qStart, int* qEnd);
int isEmpty(int Q[MAX_BOARD], int* qStart, int* qEnd);

int isUFree(int M[MAX_BOARD][2], int u);
int isVFree(int M[MAX_BOARD][2], int v);
int isElemOfM(int M[MAX_BOARD][2], int w, int u);
int reInitializeQ(int Q[MAX_BOARD], int M[MAX_BOARD][2], int VVertices, int* qStart, int* qEnd);
int isBipartite(int G[MAX_BOARD][MAX_BOARD], int VVertices);

// Main

int main(int argc, char *argv[])
{
   int numNodes = atoi(argv[1]);
   int matrix[MAX_BOARD][MAX_BOARD];
   
   int i, j, k, count;

   // Read in matrix
   j = 0;
   for (k = 0; k < numNodes - 1; k++)
   {
      count = 0;
      for (i = k + 1; i < numNodes; i++)
      {
         matrix[k][i] = atoi(argv[2 + j + count]);
         count++;
      }
      j += count;
   }

   // make it a adjacency matrix
   for (i = 0; i < numNodes; i++)
   {
      for (j = 0; j < i + 1; j++)
      {
         matrix[i][j] = 0;
      }
   }
   for (i = 0; i < numNodes; i++)
   {
      for (j = 0; j < numNodes; j++)
      {
         matrix[j][i] = matrix[i][j];
      }
   }

   for (i = 0; i < numNodes; i++)
   {
      for (j = 0; j < numNodes; j++)
      {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }

   isBipartite(matrix, numNodes);
   return 0;
}

// Returns 1 if bipartite, 0 else
   
int isBipartite(int G[][MAX_BOARD], int VVertices)
{
   // its unfortunate that global variables are not allowed.
   int qStart = 0;
   int qEnd = 0;

   int colorArr[MAX_BOARD];
   int i;
   for (i=0; i < MAX_BOARD; ++i)
   {
      colorArr[i] = -1;
   }

   // Assign first color to source
   colorArr[0] = 0;

   // Create a queue (FIFO) of vertex
   // numbers and enqueue source vertex
   // for BFS traversal
   int Q[MAX_BOARD];
   enqueue(Q, 0, &qStart, &qEnd);

   while (!isEmpty(Q, &qStart, &qEnd))
   {
      // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
      int u = top(Q, &qStart, &qEnd);
      dequeue(Q, &qStart, &qEnd);

      // Return false if there is a self-loop
      if (G[u][u] == 1)
      {
         printf("Graph is NOT Bipartite\n");
         return 0;
      }

      // Find all non-colored adjacent vertices
      int v;
      for (v=0; v < MAX_BOARD; ++v)
      {
         // An edge from u to v exists and
         // destination v is not colored
         if (G[u][v] && colorArr[v] == -1)
         {
            // Assign alternate color to this adjacent v of u
            colorArr[v] = 1 - colorArr[u];
            enqueue(Q, v, &qStart, &qEnd);
         }

         // An edge from u to v exists and destination
         // v is colored with same color as u
         else if (G[u][v] && colorArr[v] == colorArr[u])
         {
            printf("Graph is NOT Bipartite\n");
            return 0;
         }
      }
   }
 
   printf("Graph is Bipartite\n");
   // If we reach here, then all adjacent 
   // vertices can be colored with alternate color
   return 1;
}


// Note: These are my print functions. Your may vary if you have different data structures.
// Print the adjacentcy matrix.

void printGraph(int G[MAX_BOARD][MAX_BOARD], int Vverticies) {
   int i, j;
   for(i=0; i<Vverticies; i++)
   {
      printf("%d ->", i);
      j=0;
      while(G[i][j] != BCEMPTY)
      {
         printf(" %d", G[i][j]);
         j++;
      }
      printf("\n");
   }
}

// Print out the current contents of the queue for debugging

void printQueue(int Queue[], int start, int end) {
   int i;
   printf("Queue:");
   for(i=start; i<end; i++)
   {
      printf(" %d", Queue[i]);
   }
   printf("\n");
}

// Print out the currenlty found matchings

void printM(int M[][2], int start, int end) {
   int i;
   for(i=start; i<end; i++)
   {
      printf("\tV%d", M[i][0]);
   }
   printf("\n");

   for(i=start; i<end; i++)
   {
      printf("\t|");
   }
   printf("\n");

   for(i=start; i<end; i++)
   {
      printf("\tU%d", M[i][1]);
   }
   printf("\n");
}

// 1 if u free else 0

int isUFree(int M[MAX_BOARD][2], int u)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][1] == BCEMPTY)
      {
         return 1;
      }

      if (M[i][1] == u)
      {
         return 0;
      }
   }

   return 1;
}

// 1 if v free else 0

int isVFree(int M[MAX_BOARD][2], int v)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][0] == BCEMPTY)
      {
         return 1;
      }

      if (M[i][0] == v)
      {
         return 0;
      }
   }

   return 1;
}

// 1 on reinitlalize

int reInitializeQ(int Q[MAX_BOARD], int M[MAX_BOARD][2], int VVertices, int* qStart, int* qEnd)
{
   int i;
   *qStart = 0;
   *qEnd = 0;
   for (i=0; i < VVertices; i++)
   {
      if (isVFree(M, i))
      {
         enqueue(Q, i, qStart, qEnd);
      }

   }
   return 1;
}

// 1 on is elem of m else 0

int isElemOfM(int M[MAX_BOARD][2], int w, int u)
{
   int i;
   for (i=0; i < MAX_BOARD; i++)
   {
      if (M[i][0] == BCEMPTY)
      {
         return 0;
      }
      if (M[i][0] == w && M[i][1] == u)
      {
         return 1;
      }
   }
   return 0;
}

// Enqueue

void enqueue(int Q[MAX_BOARD], int val, int* qStart, int* qEnd)
{
   Q[*qEnd] = val;
   (*qEnd)++;


}

// Dequeue

void dequeue(int Q[MAX_BOARD], int* qStart, int* qEnd)
{
   (*qStart)++;
}

// Top

int top(int Q[MAX_BOARD], int* qStart, int* qEnd)
{
   return Q[*qStart];
}

// 1 if empty else 0

int isEmpty(int Q[MAX_BOARD], int* qStart, int* qEnd)
{
   if (*qStart >= *qEnd)
   {
      return 1;
   }
   return 0;
}
