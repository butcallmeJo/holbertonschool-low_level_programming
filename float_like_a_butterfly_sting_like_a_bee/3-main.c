#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int, int);

void print_grid(int **grid, int height, int width) {
  int w, h;

  for (h=0; h<height; h++) {
    /* code */
    for (w=0; w<width; w++) {
      /* code */
      printf("%d", grid[h][w]);
      if (w != width-1) {
        /* code */
        printf(", ");
      }
    }
    printf("\n");
  }
}

int main()
{
  int **grid;

  grid = alloc_grid(5, 5);
  print_grid(grid, 5, 5);
  printf("\n");
  grid[2][3] = 98;
  grid[4][4] = 402;
  print_grid(grid, 5, 5);
  return (0);
}
