/*insertion sort function*/
void insertion_sort(int *array, int size)
{
	int i, j;
	int temp;
	for (i = 0; i < size; i++) {
		j=i;
		for (;j > 0 && array[j] < array[j-1]; j--) {
			temp = array[j-1];
			array[j-1] = array[j];
			array[j] = temp;
		}
	}
}
