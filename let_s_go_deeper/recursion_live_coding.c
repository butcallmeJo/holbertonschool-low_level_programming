#include <stdio.h>
void print(char * begin, char * end);
void print2(char * c, char * d);
char *find_end(char *c);

void main () {
  char * c = "Hell0!";
  print2(c, find_end(c));
  printf("\n%s\n", "done");
}

void print(char * begin, char * end) {
  /*printf("%c", *begin);*/
  printf("%c", *end);
  if ( *begin != 0) {
    print(++begin, --end);
  }
}

char *find_end(char * c) {
  if (*c ==0) {
    return (c);
  }
  find_end(++c);
}

void print2(char * begin, char * end) {
  if (end != begin) {
    print(begin, --end);
  }
}
