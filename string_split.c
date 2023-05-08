#include "main.h"
/**
 * tokenize - creates an array of string
 * @path: path to the command
 * @delim: delimeter to seperate the string
 * Return: Array of string
 */
char **tokenize(char *path, char *delim)
{
char **av, *token, *path_cpy;
int count = 0, i = 0;
path_cpy = strdup(path);
token = strtok(path_cpy, delim);
while (token)
{
count++;
token = strtok(NULL, delim);
}
count++;
free(path_cpy);
av = malloc(sizeof(char *) * count);
token = strtok(path, delim);
while (token)
{
av[i++] = strdup(token);
token = strtok(NULL, delim);
}
av[i] = NULL;
return (av);
}
