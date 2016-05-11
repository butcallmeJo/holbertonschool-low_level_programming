#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int print_char(char c);

/*function to print out the content of a file*/
int main(int argc, char *argv[]) {
  int i;
  int fd;
  char *buffer;
  struct stat fileStat;

  /*error and parameter checking*/
  if (argc != 2) return 1;
  if (stat(argv[1],&fileStat) < 0) return 1;

  buffer = malloc(fileStat.st_size);
  fd = open(argv[1], O_RDONLY);

  read(fd, buffer, fileStat.st_size);

  /*writing the buffer to the standard output*/
  for (i=0; i<fileStat.st_size; i++) {
    print_char(buffer[i]);
  }
  close(fd);
  free(buffer);
  return 0;
}
