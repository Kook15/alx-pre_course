#include "main.h"
/**
 * path - shows current shell
 * @command: pointer to a string
 * Return: buffer or Null
 */
char *path(char *command)
{
char **av, *path_dir, *buffer, *path_cpy;
struct stat sta;
int i = 0;
path_dir = getenv("PATH");
path_cpy = strdup(path_dir);
av = tokenize(path_cpy, ":");
free(path_cpy);
while (av[i])
{
buffer = malloc(sizeof(char) * (strlen(av[i]) + strlen(command) + 2));
snprintf(buffer, strlen(av[i]) + strlen(command) + 2, "%s/%s", av[i], command);
if (stat(buffer, &sta) == 0)
{
free_argv(av);
return (buffer);
}
free(buffer);
i++;
}
free_argv(av);
buffer = malloc(sizeof(char) * strlen(command));
buffer = strdup(command);
if (stat(command, &sta) == 0)
{
return (buffer);
}
free(buffer);
return (NULL);
}
