#include "main.h"
/**
 * set_env - intialises a new variable or modify an existing one
 * @args: array of string
 * Return: 1 for sucess else fail
 */
int set_env(char **args)
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return (2);
}
else if (args[3] != NULL)
{
fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
return (2);
}
else
{
if (setenv(args[1], args[2], 1) == -1)
{
perror("setenv");
return (2);
}
return (1);
}
}
