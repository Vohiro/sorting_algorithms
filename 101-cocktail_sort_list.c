#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swapnode_ahead - To swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: the head of a doubly-linked list of integers.
 * @tail: the tail of the doubly-linked list.
 * @shaker: the current swapping node of the cocktail shaker algo.
 */
void swapnode_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *template = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = template;
	else
		*list = template;
	template->prev = (*shaker)->prev;
	(*shaker)->next = template->next;
	if (template->next != NULL)
		template->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = template;
	template->next = *shaker;
	*shaker = template;
}

/**
 * swapnode_behind - To swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: the head of a doubly-linked list of integers.
 * @tail: the tail of the doubly-linked list.
 * @shaker: the current swapping node of the cocktail shaker algo.
 */
void swapnode_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *template = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = template;
	else
		*tail = template;
	template->next = (*shaker)->next;
	(*shaker)->prev = template->prev;
	if (template->prev != NULL)
		template->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = template;
	template->prev = *shaker;
	*shaker = template;
}

/**
 * cocktail_sort_list - To sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swapnode_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swapnode_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
