#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: list of unsorted data
 * @size: size of the list of unsorted data
 *
 * Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* perform print operation now */
				print_array(array, size);
			}
			j++;
		}
		i++;
	}

}
