#include <stdlib.h>
void print_array_of_strings(char **a);

int main(void)
{
     char *a[] =
     {
          "Life",
          "is",
          "full",
          "of",
          "surprises,",
          "so you may as well get used to it",
          NULL
     };
     print_array_of_strings(a);
     return (0);
}
