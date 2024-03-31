#include "monty.h"
/**
 * _rotl -  rotates the stack to the top.
 * @stack: top of stack
 * @num: file line number
 * Return: nothing
 */
void _rotl(stack_t **stack, unsigned int num)
{
	stack_t *new_head;
	stack_t *tail;
	(void)num;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	new_head = (*stack)->next;
	new_head->prev = NULL;
	(*stack)->next = NULL;
	(*stack)->prev = tail;
	tail->next = *stack;

	*stack = new_head;
}
/**
 * _rotr -  rotates the stack to the bottom.
 * @stack: top of stack
 * @num: file line number
 * Return: nothing
 */
void _rotr(stack_t **stack, unsigned int num)
{
	stack_t *tail;
	(void)num;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = *stack;

	*stack = tail;
}
