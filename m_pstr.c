#include "monty.h"
#include <ctype.h>

/**
 * m_pstr- print string of stack of int up to null byte,
 * first non-ascii character, or end of stack
 * @stack: double pointer to head of stack
 * @line_number: line number of current operatiopn
 *
 * Return: void
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int ch;

	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		ch = temp->n;
		if (ch > 127 || ch <= 0)
			break;
		putchar(ch);
		temp = temp->next;
		if (temp == *stack)
			break;
		putchar(ch);
		temp = temp->next;
	}
	putchar('\n');
}
