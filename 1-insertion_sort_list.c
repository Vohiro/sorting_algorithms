#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly-linked list of integers.
 * @head: Head of the doubly-linked list of integers.
 * @node_1: First node to be swapped.
 * @node_2: Second node to be swapped.
 */
void swap_nodes(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}

/**
 * insertion_sort_list - Function to sort a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: List of integers of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *insert, *template;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = template)
	{
		template = i->next;
		insert = i->prev;
		while (insert != NULL && i->n < insert->n)
		{
			swap_nodes(list, &insert, i);
			print_list((const listint_t *)*list);
		}
	}
}
