/*buble sort function*/
void bubble_sort(int *array, int size)
{
	int i, j;
	int temp;

	for (i=0; i<size; i++) {
		for (j=0; j<size; j++)
			if (array[j]>array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	}
}
