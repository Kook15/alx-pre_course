#include "main.h"
/**
 * loop - prompts the user to type commands and until user types exit
 */
void loop(void)
{
	int status = 1;
	char **argv = NULL, *line = NULL, *delim = NULL;
	size_t n = 0;

	while (status)
	{
		printf(":) ");
		if (getline(&line, &n, stdin) == -1)
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("getline");
				exit(1);
			}
		}
		if (strlen(line) == 0 || strcmp(line, "\n") == 0)
		{
			continue;
		}
		delim = " \n";
		argv = tokenize(line, delim);
		status = execute(argv);
	}
	free(line);
	free_argv(argv);
}
