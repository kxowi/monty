#include "monty.h"
/**
 * add_node_start - add a new node at the beginning of the linked list
 * stack: double pointer to the beginning of the linked list
 * @n: value to add to the new node
 *
 * Return: pointer to the new node, or null on failure
 */
stack_t *add_node_start(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new ==  NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
	if (new->next != NULL)
		(new->next)->prev = new;
	return (new);
}
/**
 * add_node_end - add a new node to the end of the linked list
 * @stack: double pointer to the beginning of the linked list
 * @n: value to add to the new node
 *
 * Description: the function will add the node to the beginning if in 
 * stack mode and the end if in queue mode
 *
 * Return: pointer to the new node, or on failure
 */
stack_t *add_node_end(stack_t **stack, const int n)
{
	stack_t *new, *temp;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = new;
		*stack = new;
		return (new);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (new);
}
