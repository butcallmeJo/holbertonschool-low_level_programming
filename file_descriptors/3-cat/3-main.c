#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int print_content(char *);
void print_error(char *file);
int get_length(char *str);
int print_char(char);
void print_stdin();

/*function that acts like the cat program*/
int main(int argc, char *argv[]) {
  int inc;

  /*if no parameter, opens up a stdin for user to type in*/
  if (argc == 1) {
    print_stdin();
  }

  /*if more than 1 parameter, prints out content of files passed as arguments*/
  if (argc > 1) {
    for (inc=1; inc < argc; inc++) {
      print_content(argv[inc]);
    }
  }

  return 0;
}

/*function to print content of a file*/
int print_content(char *file) {
  int fd;
  char *buffer;
  struct stat fileStat;

  /*error and parameter checking*/
  if (stat(file, &fileStat) < 0) {
    print_error(file);
    return 1;
  }
  buffer = malloc(fileStat.st_size);
  fd = open(file, O_RDONLY);

  read(fd, buffer, fileStat.st_size);

  write(1, buffer, fileStat.st_size);
  close(fd);
  free(buffer);
  return 0;
}

/*function to print out reason a file couldn't be opened*/
void print_error(char *file) {
  write(1, "cat: ", 5);
  write(1, file, get_length(file));
  print_char(':');
  print_char(' ');
  write(1, "No such file or directory", 25);
  print_char('\n');
}

/*function to get the length of any char * passed*/
int get_length(char *str) {
  int len;
  for (len=0; str[len] != 0; len++) {}
  return len;
}

/*function to print to stout any stdin*/
void print_stdin() {
  char c;
  while(read(0, &c, 1) > 0) {
    write(1, &c, 1);
  }
}
