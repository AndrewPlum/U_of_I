/*********************************************
 * Id: plum0598
 *
 * The output of this program is the set of coords in the convex hull order listed clockwise.
 * The input is a set of command line integers representing each point (the x coordinate followed by the y coordinate).
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct coord{
   int x;
   int y;
} coord;

// Function prototypes

void extract_coords_from_args(int argc, char *argv[], coord coords[], int *coords_count);
void resize_hull(coord **hull, int *max_hull, int new_size);
void display_hull(const coord *coords, int size);
int check_side(const coord *first, const coord *second, const coord *third);
int compare_coords(const void *left, const void *right);
coord *compute_convex_hull(coord coords[], int size, int *hull_size);

int main(int argc, char *argv[]){
   int coords_count = (argc - 1) / 2;
   coord coords[coords_count];
   
   // extracting coords from command line arguments
   
   extract_coords_from_args(argc, argv, coords, &coords_count);

   // compute and display the convex hull
   
   int hull_size;
   coord *convex_hull = compute_convex_hull(coords, sizeof(coords) / sizeof(coord), &hull_size);
   printf("The points in Convex Hull are:\n");
   display_hull(convex_hull, hull_size);
   printf("\n");
   free(convex_hull);

   return 0;
}

// Extract coordinates

void extract_coords_from_args(int argc, char *argv[], coord coords[], int *coords_count){
   *coords_count = 0;
   for(int i = 1; i < argc - 1; i += 2){
      coords[*coords_count].x = atoi(argv[i]);
      coords[*coords_count].y = atoi(argv[i + 1]);
      (*coords_count)++;
   }
}

// Resize the hull

void resize_hull(coord **hull, int *max_hull, int new_size){
   *hull = realloc(*hull, new_size * sizeof(coord));
   *max_hull = new_size;
}

// Display the hull

void display_hull(const coord *coords, int size){
   if(size > 0){
      const coord *ptr = coords + size;
      const coord *first = coords + size;
      const coord *end = coords;
      
      // print coords in clockwise order
      printf("(%d, %d)", ptr->x, ptr->y);
      --ptr;
      for(; ptr > end; --ptr){
         printf(" (%d, %d)", ptr->x, ptr->y);
      }
      printf(" (%d, %d)", first->x, first->y);
   }
   printf(" ");
}

// Check if coordinates make a side

int check_side(const coord *first, const coord *second, const coord *third){
   int result = 0;
   if((second->y - first->y) * (third->x - first->x) < (second->x - first->x) * (third->y - first->y)){
      result = 1;
   }
   return result;
}

// Compare the coordinates

int compare_coords(const void *left, const void *right){
   const coord *left_coord = left;
   const coord *right_coord = right;

   // compare x coordinates
   int x_comparison = 0;
   if(left_coord->x < right_coord->x){
      x_comparison = -1;
   } 
   else if(left_coord->x > right_coord->x){
      x_comparison = 1;
   } 
   else{
      // if x coordinates are equal, compare y coordinates
      if(left_coord->y < right_coord->y){
         x_comparison = -1;
      } 
      else if(left_coord->y > right_coord->y){
         x_comparison = 1;
      }
   }
   return x_comparison;
}

// Compute the convex hull

coord *compute_convex_hull(coord coords[], int size, int *hull_size){
   if(size == 0){
      // no coords, return an empty hull
      *hull_size = 0;
      return NULL;
   }

   int i, count = 0, max_hull = 4;
   coord *hull = malloc(max_hull * sizeof(coord));

   // sort coords based on coordinates
   qsort(coords, size, sizeof(coord), compare_coords);

   // first, handle the bottom half of the hull
   for(i = 0; i < size; ++i){
      while (count >= 2 && !check_side(&hull[count - 2], &hull[count - 1], &coords[i])){
         --count;
      }
      if(count == max_hull){
         // double the hull size if needed
         resize_hull(&hull, &max_hull, max_hull * 2);
      }
      hull[count++] = coords[i];
   }

   // then, handle the top half of the hull
   int t = count + 1;
   for(i = size - 1; i >= 0; i--){
      while (count >= t && !check_side(&hull[count - 2], &hull[count - 1], &coords[i])){
         --count;
      }
      if(count == max_hull){
         // double the hull size if needed
         resize_hull(&hull, &max_hull, max_hull * 2);
      }
      hull[count++] = coords[i];
   }
   
   --count;
   // resize the hull array to the final count
   resize_hull(&hull, &max_hull, count);
   *hull_size = count;
   
   return hull;
}
