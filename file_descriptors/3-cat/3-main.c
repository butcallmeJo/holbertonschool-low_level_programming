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


int main(int argc, char *argv[]) {
  int inc;

  if (argc == 1) {
    print_stdin();
  }

  if (argc > 1) {
    for (inc=1; inc < argc; inc++) {
      print_content(argv[inc]);
    }
  }

  return 0;
}

int print_content(char *file) {
  int fd;
  char *buffer;
  struct stat fileStat;

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

void print_error(char *file) {
  write(1, "cat: ", 5);
  write(1, file, get_length(file));
  print_char(':');
  print_char(' ');
  write(1, "No such file or directory", 25);
  print_char('\n');
}

int get_length(char *str) {
  int len;
  for (len=0; str[len] != 0; len++) {}
  return len;
}

void print_stdin() {
  char c;
  while(read(0, &c, 1) > 0) {
    write(1, &c, 1);
  }
}
