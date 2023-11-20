#include "monty.h"
/**
 * _strcmp - compare two string
 * @s1: pointer to str
 * @s2: pointer to str
 * Return: 1 if right or 0 false
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0 ; s1[i] ; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
/**
 * getfunc - function return function pointer
 * @str: pointer to str
 * Return: function pointer
 */
void (*getfunc(char *str))(stack_t **, size_t)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (inst[i].opcode)
	{
		if (_strcmp(str, inst[i].opcode))
			return (inst[i].f);
		i++;
	}
	return (NULL);
}
