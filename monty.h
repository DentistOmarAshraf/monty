#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - D.linked list represent stack (or queue)
 * @n: int
 * @prev: pointer to prev Node
 * @next: pointer to next Node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle opcode
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **, size_t line_number);
} instruction_t;
/*-------------List function-----------*/
void chkstruct(stack_t *);
void free_list(stack_t *);
size_t print_list(stack_t *);
size_t list_size(stack_t *);
stack_t *add_node(stack_t **, int);
stack_t *add_node_end(stack_t **, int);
stack_t *insert_node(stack_t **, int, size_t);
/*------------opcode function-----------*/
void (*getfunc(char *))(stack_t **, size_t);
void push(stack_t **, size_t);
void pall(stack_t **, size_t);
/*-----------helper function------------*/
int _strlen(char *);

#endif
