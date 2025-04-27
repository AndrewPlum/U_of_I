/*********************************************
 * Id: plum0598
 *
 * The clique problem is the optimization problem of finding a clique of maximum size in a graph.
 * This program does an exhaustive-search algorithm for determining the number of verticies 
 * in the largest clique in the graph.
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// Function prototypes

void read_graph(int size, int graph[][size], char *argv[]);
int identify_clique(int size, int current_row, int total, int selected_nodes[], int adjacency_graph[][size]);
int compute_max_clique(int size, int adjacency_graph[][size]);

// Main function

int main(int argc, char *argv[]){
   
   // get the size of the graph from command line arguments
   
   int size = atoi(argv[1]);
   int graph[size][size];

   // read the graph from command line arguments
   
   read_graph(size, graph, argv);

   // print the adjacency matrix
   
   for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
         printf("%d ", graph[i][j]);
      }
      printf("\n");
   }

   // calculate the maximum clique and print the results
   
   int result = compute_max_clique(size, graph);
   
   for(int i = size; i > 0; i--){
      switch (result < i){
         case 1:
         printf("No clique found of size %d\n", i);
         break;
         case 0:
         switch (result == i){
            case 1:
            printf("Clique found of size %d\n", i);
            break;
         }
         break;
      }
   }

   // end of program

   return 0;
}

// Reads the graph from command line arguments

void read_graph(int size, int graph[][size], char *argv[]){
   int i, j, k, element_count;

   // read in graph
   
   j = 0;
   for(k = 0; k < size - 1; k++){
      element_count = 0;
      for(i = k + 1; i < size; i++){
         graph[k][i] = atoi(argv[2 + j + element_count]);
         element_count++;
      }
      j += element_count;
   }

   // fill lower triangle with zeros
   
   for(i = 0; i < size; i++){
      for(j = 0; j < i + 1; j++){
         graph[i][j] = 0;
      }
   }

   // mirror upper triangle to lower triangle
   
   for(i = 0; i < size; i++){
      for(j = 0; j < size; j++){
         graph[j][i] = graph[i][j];
      }
   }
}

// Finds the clique from an adjacency graph

int identify_clique(int size, int current_row, int total, int selected_nodes[], int adjacency_graph[][size]){
   int index;
   int vertex_count = 0;

   // count the number of adjacent vertices in the current row
   
   for(index = 0; index < size; index++){
      vertex_count += (selected_nodes[index] == 1 && adjacency_graph[current_row][index] == 1);
   }

   // return result

   return (vertex_count == total);
}

// Calculates and returns the max clique

int compute_max_clique(int size, int adjacency_graph[][size]){
   int i, j, k, l, vertex_count, max_clique;
   int selected_nodes[size];

   // initialize the maximum clique and vertex count
   
   max_clique = 2;
   vertex_count = 1;

   // iterate through each vertex as a potential starting point for a clique
   
   for(l = 0; l < size; l++){
      
      // initialize the selected nodes array
      
      for(j = 0; j < size; j++){
         selected_nodes[j] = 0;
      }

      // mark the current vertex as selected
      
      selected_nodes[l] = 1;

      // check adjacent vertices for clique formation
      
      for(i = 0; i < size; i++){
         k = 0;

         if(adjacency_graph[l][i] == 1){
            k = identify_clique(size, i, vertex_count, selected_nodes, adjacency_graph);
         }

         // if a clique is identified, update the vertex count and selected nodes
         
         if(k == 1){
            vertex_count++;
            selected_nodes[i] = 1;
         }
      }

      // update the maximum clique size
      
      if(vertex_count > max_clique){
         max_clique = vertex_count;
      }

      // reset vertex count for the next iteration
      
      vertex_count = 1;
   }

   // return max clique

   return max_clique;
   
}
