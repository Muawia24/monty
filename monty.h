#ifndef MONTY_H
#define MONTY_H

#define  _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int count;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buf;
} global_t;


/* get_opcode.c */
void (*get_opcode(char *op))(stack_t **stack, unsigned int line_number);

extern global_t globs;

/* monty_func.c instructions functions */
void _push(stack_t **stack, unsigned int num);
void _pall(stack_t **stack, unsigned int num);
void _pint(stack_t **stack, unsigned int num);
void _pop(stack_t **stack, unsigned int num);
void _swap(stack_t **stack, unsigned int num);
void _add(stack_t **stack, unsigned int num);
void _nop(stack_t **stack, unsigned int num);
void _sub(stack_t **stack, unsigned int num);
void _div(stack_t **stack, unsigned int num);
void _mul(stack_t **stack, unsigned int num);
void _mod(stack_t **stack, unsigned int num);
void _pchar(stack_t **stack, unsigned int num);
void _pstr(stack_t **stack, unsigned int num);
void _rotl(stack_t **stack, unsigned int num);
void _rotr(stack_t **stack, unsigned int num);

/* d_lists.c linked list functions*/

stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main.c*/
void free_globs(void);

#endif
