int print_char(char c);

/*function that reverses the content of an array of integers*/
void reverse_array(int *a, int n)
{
  int count0, count1, temp;
  count0 = temp = 0;
  count1 = n;
  while (count1>n/2)
  {
    temp=a[count0]; /*temporary int to store a[count0]*/
    a[count0]=a[count1-1]; /*replacing a[count0]*/
    a[count1-1]=temp; /*replacing a[count1-1]*/
    count1--;
    count0++;
  }
}
