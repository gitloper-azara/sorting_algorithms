#include "sort.h"

/**
 * shell_sort - a function that sorts an array in ascending order using
 * Shellsort algorithm with the Knuth sequence
 * @array: The list to be sorted
 * @size: size of the list
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* calculate the initial gap using Knuth sequence */
        while (gap < size / 3)
            gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* perform a gapped insertion sort for every elements in gaps */
		for (i = gap; i < size; i++)
		{
			/*
			 * save array[i] in temp and make a hole at position
			 * i
			 */
			temp = array[i];
			/*
			 * shift earlier gap-sorted elements up until the
			 * correct location for array[i] is found
			 */
			for (j = i; (j >= gap) && (array[j - gap] > temp);
			     j -= gap)
				array[j] = array[j - gap];
			/*
			 * put temp (the original array[i]) in its correct
			 * location
			 */
			array[j] = temp;
		}
		/* print the array after decreasing gap */
		print_array(array, size);

		 /* reduce the gap using Knuth Sequence */
		gap /= 3;
	}
}
