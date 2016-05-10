#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int fd, fd2, size;
  char *buffer;
  struct stat fileStat;

  if (argc != 3) return 1;
  if (stat(argv[1],&fileStat) < 0) return 1;
  buffer = malloc(fileStat.st_size);
  size = fileStat.st_size;
  if (stat(argv[2],&fileStat) < 0) {

  }

  fd = open(argv[1], O_RDONLY);
  fd2 = open(argv[2], O_CREAT | O_WRONLY, 0666);

  read(fd, buffer, size);
  write(fd2, buffer, size);

  free(buffer);
  close(fd);
  close(fd2);

  return 0;
}
