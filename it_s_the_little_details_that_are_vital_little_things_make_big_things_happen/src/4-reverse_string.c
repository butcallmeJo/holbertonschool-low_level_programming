void reverse_string(char *s)
{
  int count0, count1, len;
  char temp;
  count0 = count1 = len = 0;
  temp='a';
  /*to count the length of array s not including the array terminator*/
  while (s[len]!='\0') {len++;}
  count1=len;
  while (count1>len/2)
  {
    temp=s[count0]; /*temporary char to store s[count0]*/
    s[count0]=s[count1-1]; /*replacing s[count0]*/
    s[count1-1]=temp; /*replacing s[count1-1]*/
    count1--;
    count0++;
  }
}
