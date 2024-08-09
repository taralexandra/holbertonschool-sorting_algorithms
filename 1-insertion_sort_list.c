#include "sort.h"

/**
* insertion_sort_list - sorts doubly linked list of ints in ascending order
* @list: pointer to header of list
*
* Return: Nothing
*/


void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	for (node = (*list)->next; node; node = tmp)
	{
		tmp = node->next;

	while (node->prev && node->n < node->prev->n)
	{
		node->prev->next = node->next;
		if (node->next)
			node->next->prev = node->prev;

		node->next = node->prev;
		node->prev = node->prev->prev;
		node->next->prev = node;

		if (node->prev)
			node->prev->next = node;
		else
			*list = node;

		print_list(*list);
		}
	}
}
