#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: head of linked list
 * @line_number: line number of the instruction
 *
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (globalvar.token2 == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	if (!_isdigit() || stack == NULL)
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}
	n = atoi(globalvar.token2);
	if (*stack == NULL)
	{
		create_node_stackfirst(stack, n);
	}
	else
	{
		create_node_stackend(stack, n);
	}
}

/**
 * pall - pall prints all the values on the stack
 * @stack: head of linked list
 * @line_number: line number of the instruction
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		free_dlistint(*stack);
		free_globalvars();
		exit(EXIT_SUCCESS);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d", temp->n);
		temp = temp->prev;
		printf("\n");
	}
	printf("%d\n", temp->n);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: head of linked list
 * @line_number: line number of the instruction
 *
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		pint_e(line_number);
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	printf("%d", temp->n);
	printf("\n");
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: head of linked list
 * @line_number - line number of the instruction
 *
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i, j;

	if (*stack == NULL || stack == NULL)
		op_e(line_number, "swap");

	temp = (*stack)->next;
	if ((*stack)->next == NULL)
		op_e(line_number, "swap");
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	i = temp->n;
	j = temp->prev->n;
	temp->n = j;
	temp->prev->n = i;
}

/**
 * nop - does not do anything
 * @stack: head of linked list
 * @line_number: line number of the instruction
 *
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}