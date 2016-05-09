#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int print_char(char c);

int main(int argc, char *argv[]) {
  int i;
  int fd;
  char buffer[2048];
  struct stat fileStat;

  if (argc != 2) return 1;
  if (stat(argv[1],&fileStat) < 0) return 1;

  fd = open(argv[1], O_RDONLY);

  read(fd, buffer, fileStat.st_size);

  for (i=0; i<fileStat.st_size; i++) {
    print_char(buffer[i]);
  }
  return 0;
}
