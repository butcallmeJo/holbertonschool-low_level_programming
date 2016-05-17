#include <stdlib.h>

int get_words(char *str, char seperator);
int get_word_len(char *fast, char seperator);

/*
 * Function that splits strings into array of strings depending on
 * seperator.
 * TODO: split into multiple functions
 */
char **string_split(char *ptr, char seperator)
{
	char **ret;
	char *ret_ptr;
	int count = 0;
	int word_count = 0;
	count = get_words(ptr, seperator);
	if (count == 0) {
		ret = malloc(sizeof(char *)*1);
		ret[0] = NULL;
		return ret;
	}
	ret = malloc(sizeof(char *) * (count+2));
	while (*ptr != 0) {
		while (*ptr == seperator)
			ptr++;
		count = get_word_len(ptr, seperator);
		ret[word_count] = malloc(sizeof(char) * (count + 1));
		ret_ptr = ret[word_count];
		while (*ptr != seperator && *ptr != 0) {
			*ret_ptr = *ptr;
			ret_ptr++;
			ptr++;
		}
		while (*ptr == seperator)
			ptr++;
		*ret_ptr = 0;
		word_count++;
	}
	ret[word_count] = 0;
	return ret;
}

/*
 * gets the number of segments to break the string into
 */
int get_words(char *ptr, char seperator)
{
	int count = 0;
	while (*ptr != 0) {
		while (*ptr == seperator)
			ptr++;
		if (*ptr == 0)
			break;
		while (*ptr != seperator && *ptr != 0)
			ptr++;
		count++;
	}
	return count;
}

/*
 * gets the length of the segment starting at fast
 */
int get_word_len(char *fast, char seperator)
{
	int count = 0;
	while (*fast != seperator && *fast != 0) {
		count++;
		fast++;
	}
	return count;
}
