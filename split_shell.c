#include "shell.h"


/**
 * swap_char - chars | and &swaps given for file inputs
 *
 * @input: input strings
 * @bool: type of swap
 * Return: swapped strings
 */

char *swap_char(char *input, int bool)

{

	int i;

	if (bool == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_nodes - add and increase  separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @input: input string
 * Return: no return
 */

void add_nodes(sep_list **head_s, line_list **head_l, char *input)

{
	int k;
	char *line;

	input = swap_char(input, 0);

	for (k = 0; input[k]; k++)
	{
		if (input[k] == ';')
			add_sep_node_end(head_s, input[k]);

		if (input[k] == '|' || input[k] == '&')
		{
			add_sep_node_end(head_s, input[k]);
			k++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_char(line, 1);
		add_line_node_end(head_l, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * go_next - go to the next loop of file line stored
 *
 * @list_s: sep lists
 * @list_l: command line list
 * @datash: data structure
 * Return: no return
 */

void go_next(sep_list **list_s, line_list **list_l, data_shell *datash)

{

	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{

		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * split_commands - command lines according to
 * the separators ;, | and &, and executes all files
 *
 * @datash: data input
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */

int split_commands(data_shell *datash, char *input)

{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int loop;

	head_s = NULL;
	head_l = NULL;

	add_nodes(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		go_next(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	free_sep_list(&head_s);
	free_line_list(&head_l);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - chokes the input of the strings
 *
 * @input: input string
 * Return: string splitted accross the file.
 */

char **split_line(char *input)

{
	size_t base;
	size_t z;
	char **chokes;
	char *choke;

	base = TOK_BUFSIZE;
	chokes = malloc(sizeof(char *) * (base));
	if (chokes == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	choke = _strtok(input, TOK_DELIM);
	chokes[0] = choke;

	for (z = 1; choke != NULL; z++)
	{
		if (z == base)
		{
			base += TOK_BUFSIZE;
			chokes = _reallocdp(chokes, z, sizeof(char *) * base);
			if (chokes == NULL)

			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		choke = _strtok(NULL, TOK_DELIM);
		chokes[z] = choke;
	}

	return (chokes);
}
