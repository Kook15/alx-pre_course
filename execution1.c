#include "main.h"
/**
 * execute - execute a command
 * @argv: array of string
 * Return: 1 for sucesss else fail
 */
int execute(char **argv)
{
pid_t pid;
char *command_path;
int i, status;
char *builtin_arr[] = {"cd", "exit", "env", "setenv", "unsetenv"};
int size = sizeof(builtin_arr) / sizeof(builtin_arr[0]);
int (*func_ptr[])(char **) = {&change_dir, &exit_shell, &env_vars, &set_env,
			      &unset_env};
for (i = 0; i < size; i++)
{
if (strcmp(argv[0], builtin_arr[i]) == 0)
	return ((*func_ptr[i])(argv));
}
command_path = path(argv[0]);
if (command_path == NULL)
{
fprintf(stderr, "%s: Command not found\n", argv[0]);
return (2);
}
pid = fork();
if (pid == 0)
{
if (execve(command_path, argv, NULL) == -1)
{
perror("execve");
return (3);
}
}
else
{
if (wait(&status) == -1)
{
perror("wait");
return (4);
}
}
free(command_path);
return (1);
}
