#include "sort.h"

/**
 * max_array - computes the maximum of an array
 *
 * @array: array of integers
 * @size: the size of the array
 * Return: the maximum of the array
 */

int max_array(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 *		using the Counting sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sort_output, k;
	size_t i;

	if (!array || size < 2)
		return;
	k = max_array(array, size);

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	sort_output = malloc(sizeof(int) * size);
	if (sort_output == NULL)
	{
		free(count);
		return;
	}

	for (i = 0; i <= (size_t)k; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		++count[array[i]];

	for (i = 1; i <= (size_t)k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);

	for (i = 0; i < size; i++)
		sort_output[--count[array[i]]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = sort_output[i];

	free(sort_output);
	free(count);
}
