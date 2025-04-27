/*********************************************
 * Id: plum0598
 *
 * This program sorts an array of integers 
 * passed as arguments using an insertion sort
 * algorithm. 
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

// typedef

typedef struct Point
{
   int x, y;
} Point;

// Prototypes

int isSide(const Point *a, const Point *b, const Point *c);
int comparePoints(const void *left, const void *right);
void printHull(const Point *points, int size);
Point *convexHull(Point points[], int size, int *hullSize);

// Main

int main(int argc, char *argv[])
{
   int pointsSize = (argc - 1) / 2;
   Point points[pointsSize];

   int i;
   int currPoint = 0;
   for (i = 1; i < argc - 1; i++)
   {
      if (i % 2 != 0)
      {
         points[currPoint].x = atoi(argv[i]);
         points[currPoint].y = atoi(argv[i + 1]);
         currPoint++;
      }
   }

   int hullSize;
   Point *hull = convexHull(points, sizeof(points) / sizeof(Point), &hullSize);
   printf("The points in Convex Hull are:\n");
   printHull(hull, hullSize);
   printf("\n");
   free(hull);

   return 0;
}

// Checks if a point is part of the side/edge

int isSide(const Point *a, const Point *b, const Point *c)
{
   return (b->x - a->x) * (c->y - a->y) > (b->y - a->y) * (c->x - a->x);
}

// Compares two points to see which is furthest

int comparePoints(const void *left, const void *right)
{
   const Point *leftPoint = left;
   const Point *rightPoint = right;

   // Check x coord
   if (leftPoint->x < rightPoint->x)
   {
      return -1;
   }

   if (rightPoint->x < leftPoint->x)
   {
      return 1;
   }

   // Check y coord
   if (leftPoint->y < rightPoint->y)
   {
      return -1;
   }

   if (rightPoint->y < leftPoint->y)
   {
      return 1;
   }

   return 0;
}

// Displays the points in the hull

void printHull(const Point *points, int pointsSize)
{
   if (pointsSize > 0)
   {
      const Point *ptr = points + pointsSize;
      const Point *first = points + pointsSize;
      const Point *end = points;
      printf("(%d, %d)", ptr->x, ptr->y);
      --ptr;
      for (; ptr > end; --ptr)
      {
         printf(" (%d, %d)", ptr->x, ptr->y);
      }
      printf(" (%d, %d)", first->x, first->y);
   }
   printf(" ");
}

// Computes the convex hull

Point *convexHull(Point points[], int pointsSize, int *hullSize)
{
   if (pointsSize == 0)
   {
      *hullSize = 0;
      return NULL;
   }

   int i, count = 0, maxHull = 4;
   Point *hull = malloc(maxHull * sizeof(Point));

   qsort(points, pointsSize, sizeof(Point), comparePoints);

   // first do bottom half of hull
   
   for (i = 0; i < pointsSize; ++i)
   {
      while (count >= 2 && !isSide(&hull[count - 2], &hull[count - 1], &points[i]))
      {
         --count;
      }
      if (count == maxHull)
      {
         maxHull *= 2;
         hull = realloc(hull, maxHull * sizeof(Point));
      }
      hull[count++] = points[i];
   }

   // then do top half of hull
   
   int t = count + 1;
   for (i = pointsSize - 1; i >= 0; i--)
   {
      while (count >= t && !isSide(&hull[count - 2], &hull[count - 1], &points[i]))
      {
         --count;
      }
      if (count == maxHull)
      {
         maxHull *= 2;
         hull = realloc(hull, maxHull * sizeof(Point));
      }
      hull[count++] = points[i];
   }

   --count;
   hull = realloc(hull, count * sizeof(Point));
   *hullSize = count;
   return hull;
}