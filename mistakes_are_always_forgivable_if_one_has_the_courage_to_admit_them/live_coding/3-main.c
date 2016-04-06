#include <stdio.h>
void a();
void b();
void c();
void run_string(char *, void (*)(), void (*)(), void (*)(), void (*)());


void main () {
  char *str="abcfffffabc";
  run_string(str, a, b, c, c);
}

void run_string(char *str, void (*a)(), void (*b)(), void (*c)(), void (*def)()) {
  while (*str != 0) {
    switch (*str) {
      case 'a':
        a();
        break;
      case 'b':
        b();
        break;
      case 'c':
        c();
        break;
      default:
        def();
    }
    str++;
  }
}

void a() {
  printf("Hello!\n");
}

void b() {
  printf("Goodbye\n");
}

void c() {
  printf("How are you?\n");
}
