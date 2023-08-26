#include "sort.h"

/**
 * swap_nodes - swap two nodes in doubly linked list
 *
 * @list: a double pointer to the head of the list
 * @n1: a pointer to the first node
 * @n2: a pointer to the second node
 */

void swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (!list || !(*list) || !n1 || !n2)
		return;
	n1->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = n1;
	n2->prev = n1->prev;
	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;
	n2->next = n1;
	n1->prev = n2;
}

/**
 * insertion_sort_list - sorts a dl_list of integers in ascending order
 *			using the Insertion sort algorithm
 *
 * @list: a double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;
	int temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	for (current = (*list); current; current = current->next)
	{
		previous = current->prev;
		temp = current->n;
		while (previous && previous->n  > temp)
		{
			swap_nodes(list, previous, current);
			print_list(*list);
			previous = current->prev;
		}
	}
}
