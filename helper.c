#include "monty.h"

/**
 * _strlen - string lenght
 * @s: pointer to str
 * Return: int
 */
int _strlen(char *s)
{
	if (!*s)
		return (0);
	return (1 + _strlen(s + 1));
}
