int print_char(char c);

void triangles_in_the_term(int h, int n)
{
  int star, space, hcopy, starcopy, spacecopy;

  for (; n>0; n--)
  {
    star=1;
    space=h-1;
    spacecopy=space;
    starcopy=star;
    hcopy=1;
    for (; hcopy<h; hcopy++)
    {
      space=spacecopy;
      for(; space>0; space--)
      {
	print_char(' ');
      }
      spacecopy--;
      star=starcopy;
      while(star<(hcopy*2))
      {
	print_char('*');
	star++;
      }
      print_char('\n');
    }
  }
}
