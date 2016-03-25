int prime(int n, int i);

int is_prime_number(int n)
{
  int i=2;
  if (n==2 || n==3 || n==5 || n==7) return 1;
  else if (n<=1) return 0;
  else {
    return prime(n, i);
  }
}

int prime(int n, int i)
{
  if (n==i) return 1;
  else if(n%i==0) return 0;
  else {
    return prime (n, ++i);
  }
}

/*
if (i%2==0 || i%3==0 || i%5==0 || i%7 ==0) i++;
if (n%i==0) return 0;
if (n<i) return 0;
if (n==i) return 1;
i++;
prime(n, i);
*/
