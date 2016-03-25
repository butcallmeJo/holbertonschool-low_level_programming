#include <stdio.h>
void print(char * c);
void print2(char * c);
char *find_end(char *c);

void main () {
  char * c = "Hell0!";
  print2(c, find_end(c));
}

void print(char * c) {
  printf("%c", *c);
  if ( *c != 0) {
    print(++c);
  }
}

char *find_end(char * c) {
  if (*c ==0) {
    return (c);
  }
  find_end(++c);
}

void print2(char * begin, char * end) {
  printf("%c\n", *end);
  if (end != begin) {
    print(begin, --end);
  }
}
