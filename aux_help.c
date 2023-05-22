#include "shell.h"


/**
 * aux_help - The help information for the builtin help for our aux file
 * Return: no return
 */

void aux_help(void)

{

	char *dept = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, dept, _strlen(dept));
	dept = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, dept, _strlen(dept));
	dept = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, dept, _strlen(dept));
}

/**
 * aux_help_alias - Help information for the display alias
 * Return: no return
 */

void aux_help_alias(void)

{

	char *dept = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, dept, _strlen(dept));
	dept = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, dept, _strlen(dept));
}
