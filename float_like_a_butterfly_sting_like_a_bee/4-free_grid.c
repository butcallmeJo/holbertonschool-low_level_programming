#include <stdlib.h>
#include <stdio.h>

void free_grid(int **grid, int height){
  int i;
  for (i=0; i<height; i++){
    /*freeing each slot of the grid*/
    free(grid[i]);
  }
  /*freeing the whole grid*/
  free(grid);
}
