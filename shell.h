#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void set_unsetENV(char **argv, int argc);
void change_directory(char **argv);
void _getline(char *buffer);
char *_strtok(char *str, char *delimiter);
void display_prompt(void);
int get_arguments(char **argv, char *cmd, char *delim, char *bin);
void execution(char **argv, char **environ);

extern char **environ;

#endif
