#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int print_content(char *);
int print_char(char);

int main(int argc, char *argv[]) {
  int inc;

  for (inc=1; inc < argc; inc++) {
    print_content(argv[inc]);
  }

  return 0;
}

int print_content(char *file) {
  int i;
  int fd;
  char *buffer;
  struct stat fileStat;

  if (stat(file, &fileStat) < 0) return 1;
  buffer = malloc(fileStat.st_size);
  fd = open(file, O_RDONLY);

  read(fd, buffer, fileStat.st_size);

  for (i=0; i<fileStat.st_size; i++) {
    print_char(buffer[i]);
  }
  close(fd);
  free(buffer);
  return 0;
}
