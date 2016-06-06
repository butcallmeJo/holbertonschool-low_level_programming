#include <stdio.h>
#include <stdarg.h>

int do_sum(int, ...);

int main(void) {
	int sum;

	sum = do_sum(4, 98, 402, 94111, 1024);
	printf("Sum=%d\n", sum);
	return (0);
}

int do_sum(int nb, ...) {
	va_list args;
	int sum=0;
	va_start(args, nb);
	while(nb > 0) {
		sum += va_arg(args, int);
		nb--;
	}
	va_end(args);
	return sum;
}

/*
char @
string Holberton
int 98
int 402
char a
string SF
*/
