#include "sort.h"

/**
 * shell_sort - sorts array of ints in ascending order
 *	using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: array of integers
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, n;
	int temp;

	n = 1;
	while (n < (size / 3))
		n = (n * 3) + 1;

	for (; n >= 1; n = n / 3)
	{
		for (i = n; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= n && array[j - n] > temp)
			{
				array[j] = array[j - n];
				j = j - n;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
