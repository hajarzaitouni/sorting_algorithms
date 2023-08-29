#include "sort.h"

/**
 * top_down_merge - merge subarrays using top_down merge sort algorithm
 *
 * @array: array of integers
 * @output: sorted subarray
 * @low: the start index of the array
 * @mid: the middle index of the array
 * @high: the last index of the array
 */

void top_down_merge(int *array, int *output,
		size_t low, size_t mid, size_t high)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low);
	printf("[right]: ");
	print_array(array + mid, high - mid);
	i = low;
	j = mid;
	k = 0;
	while (i < mid && j < high)
	{
		if (array[i] < array[j])
			output[k++] = array[i++];
		else
			output[k++] = array[j++];
	}
	while (i < mid)
		output[k++] = array[i++];
	while (j < high)
		output[k++] = array[j++];

	for (i = low, k = 0; i < high; i++)
		array[i] = output[k++];

	printf("[Done]: ");
	print_array(array + low, high - low);
}

/**
 * merge_recursive - sorts using merge sort algorithm recursively
 *
 * @array: array of integers
 * @output: sorted subarray
 * @low: the start index of the array
 * @high: the last index of the array
 */

void merge_recursive(int *array, int *output, size_t low, size_t high)
{
	size_t mid;

	if (low < high - 1)
	{
		mid = low + (high - low) / 2;
		merge_recursive(array, output, low, mid);
		merge_recursive(array, output, mid, high);

		top_down_merge(array, output, low, mid, high);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 *		using the Merge sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *output;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	merge_recursive(array, output, 0, size);
	free(output);
}
