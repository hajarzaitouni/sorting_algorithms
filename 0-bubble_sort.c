#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers in ascending order
 *		using Bubble sort algorithm
 * @array: array of integers
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp, swap_flag;
	size_t i, j;

	if (size < 2 || !array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swap_flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_flag = 1;
				print_array(array, size);
			}
		}
		if (swap_flag == 0)
			break;
	}
}
