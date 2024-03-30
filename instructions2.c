#include "monty.h"
/**
 * _mul - multiplies the second top element of
 *  the stack with the top element of the stack.
 *  @stack: top of stack
 *  @num: file line number
 *  Return: nothing
 */
void _mul(stack_t **stack, unsigned int num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * _mod - computes the rest of the division of the second top
 *  element of the stack by the top element of the stack.
 *  @stack: top of stack
 *  @num: file line number
 *  Return: nothing
 */
void _mod(stack_t **stack, unsigned int num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
