#include <stdio.h>
int palindrome(char *begin, char *end, int len);
char *find_end(char *end);

int is_palindrome(char *s)
{
  int len;
  char *end = find_end(s);
  len = (end - s)+1;
  return palindrome(s, end, len);
}

int palindrome(char *begin, char *end, int len)
{
  if (*begin!=*end) {
    return 0;
  }
  if (*begin==*end && (end-begin)<=0) {
    return 1;
  }
  else return palindrome(++begin, --end, len);
}

char *find_end(char * end) {
  if (*end ==0) {
    return (end-1);
  }
  return find_end(++end);
}
