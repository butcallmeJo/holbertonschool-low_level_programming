/*Program to print a cross in std ouput*/
#include <stdio.h>

int print_char(char c);
int string_to_int(char *s);

int main(__attribute__ ((unused)) int argc, char *argv[]) {
	int i, j, mid, x;
	int num;
	/*error checking*/
	if (argv[1] == NULL) {
		return 1;
	}
	/*string to int conversion of arg*/
	num=string_to_int(argv[1]);
	/*checking odd or even and assigning accordingly*/
	if (num%2==1) { x = 1; }
	else { x = 0; }
	mid = (num+1)/2;
	/*double for loop to print chars one by one*/
	for (i=1; i<=num; i++) {
		for(j=0; j<=num; j++) {
			/*prints 'X' if middle and odd*/
			if (x==1 && i==j && j==mid) {
				print_char('X');
			}
			else if (i==j) {
				print_char('\\');
			}
			else if (i+j==num+1) {
				print_char('/');
			}
			else {
				print_char(' ');
			}
		}
		print_char('\n');
	}
	return 0;
}
