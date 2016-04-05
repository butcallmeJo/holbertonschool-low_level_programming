int power(int x, int y)
{
  if (y < 0) {
    return -1;
  }
  else if (y == 0) {
    return 1;
  }
  else {
    y--;
    return (x * power(x, y));
  }
}
