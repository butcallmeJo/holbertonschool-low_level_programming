#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

/*
 * Function that will read the line inputed in the shell
 * TODO: add comments
 */
char *read_line(int fd)
{
	int maximumLineLength = 128;
	char *lineBuffer = malloc(sizeof(char) * maximumLineLength);
	char ch;
	char *line;
	int count = 0;

	read(fd, &ch, 1);
	if (lineBuffer == NULL)
		exit(1);
	while (ch != '\n') {
		if (count == maximumLineLength) {
			maximumLineLength += 128;
			lineBuffer = realloc(lineBuffer, maximumLineLength);
			if (lineBuffer == NULL)
			exit(1);
		}
		lineBuffer[count] = ch;
		count++;
		read(fd, &ch, 1);
	}
	lineBuffer[count] = '\0';
	line = malloc(sizeof(char) * (count + 1));
	string_copy(line, lineBuffer);
	free(lineBuffer);
	return line;
}
