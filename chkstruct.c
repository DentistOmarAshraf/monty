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
