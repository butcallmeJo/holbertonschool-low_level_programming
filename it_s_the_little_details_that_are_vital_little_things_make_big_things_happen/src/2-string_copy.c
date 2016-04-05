int print_char(char c);

/*function that copies a string.*/
char *string_copy(char *dest, const char *src)
{
  int i;
  /*Getting to the end of *src and adding each location to the*/
  /*correct location of *dest*/
  for (i = 0; *(src+i) != '\0'; i++)
  {
    *(dest+i) = *(src+i);
  }
  return (dest);
}
