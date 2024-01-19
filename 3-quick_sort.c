#include "sort.h"

/**
 * lomuto_partition - a function that partitions the array using the Lomuto
 * scheme
 * @array: list to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * 
 * Return: index of the pivot element
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i, pivotIdx = low;
    int temp;

    for (i = low; i <= high; i++)
    {
        if (array[i] < pivot)
        {
            if (array[i] != array[pivotIdx])
            {
                /* perform swap */
                temp = array[i];
                array[i] = array[pivotIdx];
                array[pivotIdx] = temp;
                print_array(array, size);
            }
            pivotIdx++;
        }
    }

    if (array[pivotIdx] != array[high])
    {
        /* swap the pivot element into its correct position */
        temp = array[pivotIdx];
        array[pivotIdx] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return pivotIdx;
}

/**
 * quicksort_recursive - a function that performs recursive quicksort
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: void
*/

void quicksort_recursive(int *array, int low, int high, size_t size)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, low, high, size);
        quicksort_recursive(array, low, pivot_index - 1, size);
        quicksort_recursive(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - a function that sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: list of unsorted data
 * @size: size of the array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}
