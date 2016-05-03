int print_char(char c);

void print_array_of_strings(char **a) {
  int i, j;
  for (i = 0; a[i] != 0; i++) {
    for (j = 0; a[i][j] != 0; j++) {
      print_char(a[i][j]);
    }
    if (a[i+1] != 0) {
      print_char(' ');
    }
    else if (a[i+1] == 0) {
      print_char('\n');
    }
  }
}
