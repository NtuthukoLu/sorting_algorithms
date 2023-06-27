#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (swapped)
	{
		swapped = 0;
		while (tmp->next != NULL)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_node(list, tmp);
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_node(list, tmp->prev);
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
	}
}

/**
 * swap_node - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node: pointer to the node to swap
 */
void swap_node(listint_t **list, listint_t *node)
{
	listint_t *tmp;

	if (node->prev == NULL)
	{
		tmp = node->next;
		node->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = node;
		node->prev = tmp;
		*list = tmp;
	}
	else if (node->next == NULL)
	{
		tmp = node->prev;
		node->prev = tmp->prev;
		tmp->next = NULL;
		tmp->prev = node;
		node->next = tmp;
	}
	else
	{
		tmp = node->next;
		node->next = tmp->next;
		tmp->prev = node->prev;
		tmp->next = node;
		node->prev->next = tmp;
		node->prev = tmp;
	}
}
