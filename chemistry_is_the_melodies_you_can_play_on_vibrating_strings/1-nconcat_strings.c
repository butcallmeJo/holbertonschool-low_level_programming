int print_char(char c);

/*function that concatenates two strings.*/
char *nconcat_strings(char *dest, const char *src, int n)
{
  int i, j;
  /*Getting to the end of *dest and keeping track of the location*/
  for (i = 0; *(dest+i) != '\0'; i++) {}
  /*Getting to n length of *src and adding each location to the*/
  /*end of *dest*/
  for (j = 0; j < n; j++)
  {
    /*Making sure that j does not go further than src can go*/
    if (*(src+j)=='\0') {break;}
    *(dest+i+j) = *(src+j);
  }
  return (dest);
}
