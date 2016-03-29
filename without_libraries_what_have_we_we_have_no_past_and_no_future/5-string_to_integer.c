int string_to_integer(char *s)
{
  int count, sign, flag;
  long num;
  count = num = flag = 0;
  sign = 1;
  while (s[count]!='\0') 
  {
    if (s[count] <'0' || s[count]>'9')
    {
      if (flag==1) {break;}
      if (s[count]=='-') {sign*=-1;}
    }
    else /*(s[count] >='0' && s[count]<='9')*/
    {
      num = 10 * num + (s[count]-48);
      flag = 1;
    }
    count++;
  }  
  num = sign*num;
  if (num > 2147483647 || num < -2147483648) {num=0;}
  return((int)num);
}
