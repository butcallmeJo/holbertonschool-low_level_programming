int print_char(char c);

/*function that copies a string.*/
char *string_ncopy(char *dest, const char *src, int n)
{
  int i;
  /*Getting to the end of *(src+n) and adding each location to the*/
  /*correct location of *dest*/
  for (i = 0; i < n; i++)
  {
    /*Making sure that i does not go further than src can go
     *and that dest ends if src ends*/
    if (*(src+i)=='\0')
    {
      *(dest+i)='\0';
      break;
    }
    *(dest+i) = *(src+i);
  }
  return (dest);
}
