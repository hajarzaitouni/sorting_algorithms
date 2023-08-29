#include "sort.h"

/**
 * top_down_merge - merge subarrays using top_down merge sort algorithm
 *
 * @array: array of integers
 * @low: the start index of the array
 * @mid: the middle index of the array
 * @high: the last index of the array
 */

void top_down_merge(int *array, int low, int mid, int high)
{
	int *left, *right;
	int i, j, k = low;
	int size1, size2;

	size1 = (mid - low) + 1;
	size2 = high - mid;
	left = malloc(sizeof(int) * size1);
	if (left == NULL)
		return;
	right = malloc(sizeof(int) * size2);
	if (right == NULL)
		return;
	for (i = 0; i < size1; i++)
		left[i] = array[low + i];
	for (i = 0; i < size2; i++)
		right[i] = array[mid + 1 + i];

	printf("Merging...\n[left]: ");
	print_array(left, size1);
	printf("[right]: ");
	print_array(right, size2);

	i = j = 0;
	while (i < size1 && j < size2)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < size1)
		array[k++] = left[i++];
	while (j < size2)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array + low, high - low + 1);
	free(left);
	free(right);
}

/**
 * merge_recursive - sorts using merge sort algorithm recursively
 *
 * @array: array of integers
 * @low: the start index of the array
 * @high: the last index of the array
 */
void merge_recursive(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;
		merge_recursive(array, low, mid);
		merge_recursive(array, mid + 1, high);
		top_down_merge(array, low, mid, high);
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
	if (!array || size < 2)
		return;

	merge_recursive(array, 0, size - 1);
}
