#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *divide_and_conquer(int, char*);

char  *add_digit(char digit, char *str) {
  int c = 2; /* nonzero because null terminator and extension */
  char *strc = str;
  while (*str != 0) {
    c++;
    str++;
  }
  *(strc+c-2) = digit;
  str = malloc(sizeof(char)*(c));
  str = strcpy(str, strc);
  return str;
}

char *int_to_string(int n)
{
  char *str = malloc(sizeof(char)*1);
  *str = 0;

	if (n < 0) {
    str = add_digit('-', str);
	} else {
    n = 0-n;
  }
	if (n == 0) {
    str = add_digit('0', str);
	}
	else {
		str = divide_and_conquer(n, str);
	}
  return str;
}

char *divide_and_conquer(int n, char *str)
{
	int divisor = 1;
	int a = n;
	while (a < -9) {
		a /= 10;
		divisor *= 10;
	}

	while (n < 0) {
		int to_print = n / divisor;
		n -= to_print * divisor;
		divisor /= 10;
    to_print = 0-to_print;
	  str = add_digit('0' + to_print, str);

	}
  return str;
}
