#include "monty.h"

int main(void)
{
	int i;
	stack_t *head = NULL;
	for (i = 0 ; i < 8 ; i++)
		add_node_end(&head, i);
	insert_node(&head, -10, 2);
	printf("Size of list ==> %lu\n", list_size(head));
	chkstruct(head);
	free_list(head);

	return (0);
}
