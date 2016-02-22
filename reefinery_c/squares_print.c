void print_char(char c);

/*draws a square with side-size n on the terminal*/
void print_square(int n)
{
  int vertical, horizontal;
  
  if(n==1)
    {
      print_char('o');
      print_char('\n');
    }
  else
    {
      for (vertical = n; vertical>0; vertical--)
	{
	  if (vertical==n || vertical==1)
	    {
	      for (horizontal=n; horizontal>0; horizontal--)
		{
		  if (horizontal==n || horizontal==1)
		    {
		      print_char('o');
		    }
		  else
		    {
		      print_char('-');
		    }
		}
	    }
	  else
	    {
	      print_char('|');
	      for (horizontal=n-2; horizontal>0; horizontal--)
		{
		  print_char(' ');
		}
	      print_char('|');
	    }
	  print_char('\n');
	}
    }
}
