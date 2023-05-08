#include "main.h"
/**
 * free_argv - free the array of strings
 * @argv: Array of string
 */
void free_argv(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		free(argv[i]);
		argv[i++] = NULL;
	}
	free(argv);
}
