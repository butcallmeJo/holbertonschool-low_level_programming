int get_value(int, char *, char *);

/*
 * Function that converts string to int.
 */
int string_to_int(char *s)
{
	int positive = 1;
	char *start = s;
	char *end = s;
	while (*start != 0 && (*start < '0' || *start > '9')) {
		if (*start == '-') {
			positive *= -1;
		}
		start++;
	}

	if (*start == 0) {
		return (0);
	}

	end = start;
	while (*end >= '0' && *end <= '9') {
		end++;
	}
	end--;

	return (get_value(positive, start, end));
}

/*
 * Function that returns the value of a number
 * (positive or negative).
 */
int get_value(int positive, char *start, char *end)
{
	char *current_char;
	int i;
	long current_int;
	long total =0;

	for (current_char = start; current_char <= end; current_char++) {
		current_int = *current_char - '0';
		for (i = 0; i < end - current_char; i++)
			current_int *= 10;
		total += current_int;
		if (total * positive > 2147483647 || total * positive < -2147483648)
			return (0);
	}

	return (positive * (int) total);
}
