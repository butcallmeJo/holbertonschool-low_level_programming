/*quick sort function*/
void quick_sort(int *array, int size)
{
	/*variable declaration and init*/
	int temp = 0;
	int swap_low = -1;
	int swap_high = size;
	/*returning as is partitions that are 1 or less*/
	if (size <= 1) return;
	/*swapping elements depending on position from pivot*/
	while (swap_low < swap_high) {
		/*moving the swap points if they are in correct position*/
		do {
			swap_low++;
		} while (array[swap_low] < array[size/2]);
		do {
			swap_high--;
		} while (array[swap_high] > array[size/2]);
		/*swapping the entries at low and high indices*/
		if (swap_low < swap_high) {
			temp = array[swap_low];
			array[swap_low] = array[swap_high];
			array[swap_high] = temp;
		}
	}
	/*calls quick_sort recursively, on both partitions*/
	quick_sort(array, swap_low);
	quick_sort(&(array[swap_low]), size - swap_low);
}
