#include <stdio.h>

void func1 (char c) {
  printf("%d ", c);
}

void operate_on_string(char * str, void (* func) (char)) {
  while (*str !=0) {
    /* code */
    func(*str);
    str++;
  }
}

int main() {
  char * str = "Hello";
  operate_on_string(str, func1);
  printf("d\n");
  return 0;
}
