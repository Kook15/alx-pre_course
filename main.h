#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
char **tokenize(char *, char *);
#include <sys/wait.h>
int set_env(char **args);
int unset_env(char **args);
void loop(void);
char *read_line(void);
int execute(char **);
int exit_shell(char **);
char *path(char *);
int change_dir(char **);
int env_vars(char **argv);
char *path(char *command);
void free_argv(char **);
extern char **environ;

#endif
