#include <stdlib.h>

/*
 * Function that copies a str into another.
 */
 char *string_copy(char *dest, char *src)
{
	char *ret = dest;
	while (*src != 0) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return(ret);
}
