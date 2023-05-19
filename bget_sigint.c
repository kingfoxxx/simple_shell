#include "shell.h"

/**
 * get_sigint - crtl + c call in prompt
 * @signals: Signal
 */
void get_sigint(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
