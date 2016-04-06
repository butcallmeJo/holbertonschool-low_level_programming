int advanced_search(int *array, int size, int (*check_func)(int)){
  int i = 0;
  while (i < size) {
    if ((*check_func)(*(array + i)) == 1) {
      return 1;
    }
    else if ((*check_func)(*(array + i)) != 0 && i == size) {
      return -1;
    }
    i++;
  }
  return -1;
}
