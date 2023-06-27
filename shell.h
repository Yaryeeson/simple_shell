#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int replace_variables(char *args[]);
int handle_variablles(char *args[]);
int alias (char *args[]);
void display_prompt(void);
int read_command(cahr *command);
int tokenize_command(char *command, char *args[]);
int main();
int main(void);
int execute_command(char **args)
char command[MAX_COMMAND_LENGTH];
int argCount = tokenize_command(command, args);
int cd(const char *args[]);
int multiply_numbers(int y, int a);
int cd(char *args[]);
int execute_command(char **args);
int tokenize_command(char **args);
int main(int argc, char *argv[])
char *getline(void)
void get_args(char *command, char *args[])
void execute_command(char *args[]);
int replace_variables(char *args[]);
int handle_variables(char *args[]);
int ky_setenv(char **args);
int ky_unsetenv(char **aargs);
char *find_command_in_path(char *comand);

#endif
