#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning
 *  of a dlistint_t list.
 *  @head: head of list
 *  @n: data input
 *  Return: the address of the new element,
 *   or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed");
		free_globs();
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (*head);
}

/**
 * add_dnodeint_end - adds a new node at the end
 *  of a dlistint_t list.
 *  @head: head of list
 *  @n: data input
 *  Return: the address of the new element, or
 *   NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *tail = *head;

	if (*head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed");
		free_globs();
		exit(EXIT_FAILURE);
	}
	if (*head != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
	}

	new->n = n;
	new->next = NULL;
	new->prev = tail;

	if (tail != NULL)
		tail->next = new;

	tail = new;
	if (*head == NULL)
		*head = new;

	return (new);

}
/**
 * free_dlistint - frees a dlistint_t list.
 * @head: head of list
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;

		free(current);
	}
}
