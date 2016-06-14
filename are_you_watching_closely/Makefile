all: libprintf.a
	gcc -Werror -Wextra -Wall -pedantic -c main.c printf.c
	ar -rc libprintf.a main.o printf.o

clean:
	rm main.o printf.o libprintf.a

re: clean all
