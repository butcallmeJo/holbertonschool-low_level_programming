int print_char(char c);

/*function that capitalizes all words of a string.*/
char *cap_string(char *s)
{
  int i;
  for (i=0; *(s+i) != '\0'; i++)
  {
    /*Checks that the pointer is at the beginning*/
    if (i==0)
    {
      if (*(s+i)>='a' && *(s+i)<='z')
      {
        *(s+i+1)-=32;
      }
    }
    /*capitalizes the letter after spaces, tabs and new lines*/
    if (*(s+i)==' ' || *(s+i)=='\n' || *(s+i)=='\t')
    {
      if (*(s+i+1)>='a' && *(s+i+1)<='z')
      {
        *(s+i+1)-=32;
      }
    }
  }
  return (s);
}
