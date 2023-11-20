#include "monty.h"
/**
 * push - push element to stack
 * @head: pointer of pointer of D.list
 * @line: size_t
 * Return: NONE
 */
void push(stack_t **head, size_t line)
{
	int i, num;
	char *temp;

	temp = strtok(NULL, "\0");
	printf("%s\n", temp);
	for (i = 0 ; temp[i] ; i++)
		if (temp[i] > '9' || temp[i] < '0')
			if (temp[i] != '-')
			{
				dprintf(2, "L%lu: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
	num = atoi(temp);
	add_node(head, num);
}
/**
 * pall - print list
 * @head: pointr to D.list
 * @line: line
 * Return: NONE
 */

void pall(stack_t **head, size_t line)
{
	(void) line;

	print_list(*head);
}
