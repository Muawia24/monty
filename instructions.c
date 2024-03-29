#include "monty.h"
/**
 * _push - push a number to stack
 * @stack: head of doubly list
 * @num: data to be pushed to stack
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int num)
{
	int n;
	int i = 0;

	if (!globs.arg)
	{
		dprintf(2, "L%u: usage: push integer\n", num);
		exit(EXIT_FAILURE);
	}

	for (i = 0; globs.arg[i] != '\0'; i++)
	{
		if (!isdigit(globs.arg[i]) && globs.arg[i] != '-')
		{
			dprintf(2, "L%u: usage: push integer\n", num);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(globs.arg);
	if (globs.lifo == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}
/**
 * _pall - prints all members on stack
 * @stack: head of doubly list
 * @num: file line number
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int num)
{
	stack_t *temp = *stack;
	(void)num;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: head of stack
 * @num: file line number
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int num)
{
	if (*stack == NULL)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _pop - removes the top element of the stack.
 * @stack: head of stack
 * @num: file line number
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int num)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}

	(*stack)->prev = NULL;
	*stack = (*stack)->next;
	free(temp);
}
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: head of stack
 * @num: file line number
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int num)
{
	int k = 0;
	stack_t *temp = *stack;

	while (temp)
	{
		temp = temp->next;
		k++;
	}
	if (k < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
}
