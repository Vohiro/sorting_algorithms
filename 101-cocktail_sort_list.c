#include "sort.h"

/**
 * swap_node_ahead - To swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @head: the head of the doubly-linked list of integers.
 * @tail: the tail of the doubly-linked list.
 * @swap: swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **head, listint_t **tail, listint_t **swap)
{
	listint_t *template = (*swap)->next;

	if ((*swap)->prev != NULL)
		(*swap)->prev->next = template;
	else
		*head = template;
	template->prev = (*swap)->prev;
	(*swap)->next = template->next;
	if (template->next != NULL)
		template->next->prev = *swap;
	else
		*tail = *swap;
	(*swaap)->prev = template;
	template->next = *swap;
	*swap = template;
}

/**
 * swap_node_behind - to swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @head: head of a doubly-linked list of integers.
 * @tail: tail of the doubly-linked list.
 * @swap: swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **head, listint_t **tail, listint_t **swap)
{
	listint_t *template = (*swap)->prev;

	if ((*swap)->next != NULL)
		(*swap)->next->prev = template;
	else
		*tail = template;
	template->next = (*swap)->next;
	(*swap)->prev = template->prev;
	if (template->prev != NULL)
		template->prev->next = *swap;
	else
		*head = *shaker;
	(*swap)->next = template;
	template->prev = *swap;
	*swap = template;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @head: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **head)
{
	listint_t *tail, *swap;
	bool shaken_not_stirred = false;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (tail = *head; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (swap = *head; swap != tail; swap = swap->next)
		{
			if (swap->n > swap->next->n)
			{
				swap_node_ahead(head, &tail, &swap);
				print_list((const listint_t *)*head);
				shaken_not_stirred = false;
			}
		}
		for (swap = swap->prev; swap != *head;
				swap = swap->prev)
		{
			if (swap->n < swap->prev->n)
			{
				swap_node_behind(head, &tail, &swap);
				print_list((const listint_t *)*head);
				shaken_not_stirred = false;
			}
		}
	}
}
