int print_char(char c);

/*function that concatenates two strings.*/
char *concat_strings(char *dest, const char *src)
{
  int i, j;
  /*Getting to the end of *dest and keeping track of the location*/
  for (i = 0; *(dest+i) != '\0'; i++) {}
  /*Getting to the end of *src and adding each location to the*/
  /*end of *dest*/
  for (j = 0; *(src+j) != '\0'; j++)
  {
    *(dest+i+j) = *(src+j);
  }
  return (dest);
}
