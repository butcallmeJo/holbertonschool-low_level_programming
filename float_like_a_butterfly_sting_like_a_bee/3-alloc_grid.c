#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int height, int width){
  int i = 0;
  int **grid = malloc(width*sizeof(int *));
  if (grid == NULL) return NULL;

  for (; i<height; i++) {
    /* code */
    grid[i] = malloc(sizeof(int) * height);
    if (grid[i] == NULL) return NULL;
  }
  return grid;
}
