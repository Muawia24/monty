#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @stack: top of stack
 * @num: file line number
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't add, stack too short\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
/**
 * _nop - doesn't do anything
 * @stack: top of stack
 * @num: file line number
 * Return: nothing
 */
void _nop(stack_t **stack, unsigned int num)
{
	(void)*stack;
	(void)num;
}
/**
 * _sub - subtracts the top element of the stack from
 *  the second top element of the stack.
 *  @stack: top of stack
 *  @num: file line number
 *  Return: nothing
 */
void _sub(stack_t **stack, unsigned int num)
{
	stack_t *temp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", num);
		free_globs();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
