#include "monty.h"
/**
 * chkstruct - function to chk the next and prev pointer for nodes
 * @head: pointer to head
 * Return: NONE
 */
void chkstruct(stack_t *head)
{
	stack_t *ptr = head;

	while (ptr->next)
	{
		printf("-> %d\n", ptr->n);
		ptr = ptr->next;
	}
	while (ptr)
	{
		if (!(ptr->next))
		{
			printf("<-> %d\n", ptr->n);
			ptr = ptr->prev;
			continue;
		}
		printf("<- %d\n", ptr->n);
		ptr = ptr->prev;
	}
}
/**
 * print_list - function to print linked list
 * @head: pointer to head of linked list
 * Return: size_t
 */
size_t print_list(stack_t *head)
{
	size_t count = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		count++;
	}
	return (count);
}
