#include "sort.h"
/**
 * insert_swap -  a function that swaps two nodes in a doubly linked list
 * @h: the head of the linked list
 * @first_node: the first node to swap
 * @second_node: the second node to swap
 * Return: void
 */
void insert_swap(listint_t **h, listint_t *first_node, listint_t *second_node)
{
	listint_t *ptr, *ptr2;

	if (first_node->prev == NULL && second_node->next == NULL)
	{
		first_node->next = NULL;
		second_node->prev = NULL;
		first_node->prev = second_node;
		second_node->next = first_node;
		*h = second_node;
	}
	else if (first_node->prev == NULL)
	{
		ptr2 = second_node->next;
		first_node->next = ptr2;
		second_node->prev = NULL;
		first_node->prev = second_node;
		second_node->next = first_node;
		ptr2->prev = first_node;
		*h = second_node;
	}
	else if (second_node->next == NULL)
	{
		ptr = first_node->prev;
		first_node->prev = second_node;
		second_node->next = first_node;
		second_node->prev = ptr;
		ptr->next = second_node;
		first_node->next = NULL;
	}
	else
	{
		ptr = first_node->prev;
		ptr2 = second_node->next;
		first_node->prev = second_node;
		second_node->next = first_node;
		first_node->next = ptr2;
		second_node->prev = ptr;
		ptr->next = second_node;
		ptr2->prev = first_node;
	}
}
/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using insertion sort algorithm
 * @list: the doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *temp, *temp2;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	ptr = *list;
	while (ptr != NULL)
	{
		if (ptr->prev)
		{
			if (ptr->prev->n > ptr->n)
			{
				temp = ptr;
				temp2 = ptr;
				insert_swap(list, ptr->prev, ptr);
				ptr = ptr->next;
				print_list(*list);
				while (temp2 != NULL)
				{
					if (temp2->n > temp->n)
					{
						insert_swap(list, temp2, temp);
						print_list(*list);
					}
					temp2 = temp2->prev;
				}
			}
		}
		ptr = ptr->next;
	}
}
