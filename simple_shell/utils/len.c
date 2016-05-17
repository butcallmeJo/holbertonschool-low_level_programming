/*
 * Function get the length of a char **
 * CHECKED: functions, length, width, brackets, comments
 */
int len_command(char **command)
{
	int len = 0;
	while (*command != 0) {
		len++;
		command++;
	}
	return len;
}

/*
 * Function get the length of a char *
 */
int str_len(char *str)
{
	int i=0;
	for (i=0; str[i]!=0; i++) {}
	return i;
}
