#include "monty.h"
/**
 * list_size - check number of nodes in list
 * @head: pointer to head of D.linked list
 * Return: size_t
 */

size_t list_size(stack_t *head)
{
	size_t count = 0;

	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
/**
 * add_node - function to add node to the head of D.linked list
 * @head: pointer to head of D.linked list
 * @n: int
 * Return: struct node pointer
 */

stack_t *add_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (!*head)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * add_node_end - function to add node to the tail of linked list
 * @head: pointer to head
 * @n: integer
 * Return: stack_t node
 */
stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *ptr = *head;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		(*head)->prev = NULL;
		return (new);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
	return (new);
}
/**
 * insert_node - inserting node at ceritn index
 * @head: pointer of pointer of head of linked list
 * @n: int
 * @idx: size_t (index)
 * Return: new node
 */
stack_t *insert_node(stack_t **head, int n, size_t idx)
{
	stack_t *ptr = *head;
	stack_t *new;
	size_t i;

	if (!*head || !idx)
		return (add_node(head, n));
	if (idx > list_size(*head) - 1)
		return (add_node_end(head, n));
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	for (i = 0 ; i < idx - 1 ; i++)
		ptr = ptr->next;
	new->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = new;
	new->prev = ptr;
	ptr->next = new;
	return (new);
}
/**
 * free_list - free node list
 * @head: pointer to head of D.linked list
 * Return: NONE
 */
void free_list(stack_t *head)
{
	stack_t *ptr = head;

	while (ptr->next)
	{
		ptr = ptr->next;
		free(ptr->prev);
	}
	free(ptr);
}
