#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked
 * list of integers in ascending order using the insertion
 * sort algorithm
 * @list: pointer to the head of the doubly-linked list of data
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* start with the second element, as the first is considered sorted */
	unsorted_key = (*list)->next;
	while (unsorted_key)
	{
		/**
		 * traverse the sorted portion of the list and find the
		 * correct position for the unsorted_key
		 */
		while (unsorted_key->prev && unsorted_key->n <
		       unsorted_key->prev->n)
		{
			/* adjust the pointers to perform the swap */
			unsorted_key->prev->next = unsorted_key->next;
			if (unsorted_key->next)
				unsorted_key->next->prev = unsorted_key->prev;
			unsorted_key->next = unsorted_key->prev;
			unsorted_key->prev = unsorted_key->prev->prev;
			unsorted_key->next->prev = unsorted_key;
			/**
			 * update the head of the list if unsorted_key is
			 * moved to the beginning
			 */
			if (unsorted_key->prev == NULL)
				*list = unsorted_key;
			else
				unsorted_key->prev->next = unsorted_key;
			print_list(*list);
		}
		/* move to the next unsorted element */
		unsorted_key = unsorted_key->next;
	}
}
