#include "main.h"
/**
 * env_vars - prints environment variables
 * @argv: array of string
 * Return: 1
 */
int env_vars(char **argv)
{
	char **environ_var = environ;
	int i = 0;
	(void)argv;

	while (environ_var[i])
	{
		printf("%s\n", environ_var[i++]);
	}
	return (1);
}
