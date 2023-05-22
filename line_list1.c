#include "shell.h"


/**
 * add_rvar_node - add variables at the end in malloc file
 * of a r_var lists and lines in malloc file
 * @head: head of the linked lists
 * @lvar: length of the variables.
 * @val: value of the variable.
 * @lval: length of the values required
 * Return: address of the head.
 */

r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)

{

	r_var *new, *degree;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	degree = *head;

	if (degree == NULL)
	{
		*head = new;
	}
	else
	{
		while (degree->next != NULL)
			degree = degree->next;
		degree->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - frees a r_var list
 * @head: head of the linked list.
 * Return: no return.
 */

void free_rvar_list(r_var **head)

{
	r_var *temperature;
	r_var *current;

	if (head != NULL)
	{
		current = *head;
		while ((temperature = current) != NULL)
		{
			current = current->next;
			free(temperature);
		}
		*head = NULL;
	}
}
