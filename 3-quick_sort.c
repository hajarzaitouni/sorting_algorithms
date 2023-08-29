#include "sort.h"

/**
 * swap_elem - swaps two integers
 *
 * @a: the first element to swap
 * @b: the second element to swap with
 */

void swap_elem(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - reorder the elements of the array using lomuto partition
 *
 * @array: the array of integers
 * @low: the first index of the array
 * @upper: the last index of the array
 * @size: the size of the array
 * Return: the position of the new partition
 */

int partition(int *array, int low, int upper, size_t size)
{
	int pivot = array[upper];
	int i = low - 1, j;

	j = low;
	while (j <= upper)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i < j)
			{
				swap_elem(&array[j], &array[i]);
				print_array(array, size);
			}
		}
		j++;
	}

	return (i);
}

/**
 * lomuto_sort - sorting using lomuto quiqsort partition recursively
 *
 * @array: array of integers
 * @low: the first index of the array
 * @upper: the last index of the array
 * @size: the size of the array
 */

void lomuto_sort(int *array, int low, int upper, size_t size)
{
	int pt;

	if (low < upper)
	{
		pt = partition(array, low, upper, size);
		lomuto_sort(array, low, pt - 1, size);
		lomuto_sort(array, pt + 1, upper, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *		using the Quick sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
