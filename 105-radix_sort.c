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
 * counting_sort_radix - sorts the significant digits of array of integers
 *			in ascending order using counting sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 * @digit_pos: the significant digit of an integer
 */

void counting_sort_radix(int *array, size_t size, int digit_pos)
{
	int *sort_output, count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	sort_output = malloc(sizeof(int) * size);
	if (sort_output == NULL)
		return;

	for (i = 0; i < size; i++)
		++count[(array[i] / digit_pos) % 10];

	for (i = 1; i <= 9; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
		sort_output[--count[((array[i] / digit_pos) % 10)]] = array[i];

	for (i = 0; i < size; i++)
		array[i] = sort_output[i];

	free(sort_output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 *		using the Radix sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max, digit_pos;

	max = max_array(array, size);
	for (digit_pos = 1; (max / digit_pos) > 0; digit_pos *= 10)
	{
		counting_sort_radix(array, size, digit_pos);
		print_array(array, size);
	}
}
