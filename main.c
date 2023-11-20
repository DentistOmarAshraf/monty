#include "monty.h"

/**
 * main - entry point
 * @ac: int
 * @av: char *[]
 *
 * Return: Alwyas (0)
 */

int main(int ac, char **av)
{
	FILE *file;
	int chk;
	char *input = NULL, *temp;
	ssize_t size = 0;
	void (*func)(stack_t **, size_t line);
	size_t line = 1;
	stack_t *head = NULL;

	if (ac != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((chk = getline(&input, &size, file)) != -1)
	{
		input[_strlen(input) - 1] = '\0';
		temp = strtok(input, " ");
		func = getfunc(temp);
		func(&head, line);
	}
	free_list(head);
	fclose(file);
}
