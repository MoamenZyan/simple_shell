#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

#define BUFF_SIZE 4096
#define BUFF_FLUSH -1
extern char **environ;

char *appendBuffer(ssize_t *read);

void forking(char *buffer, char *argv, int comCount);

int _strlen(char *str);

int _strcmp(char *src, char *dest);

void _strcpy(char *dest, char *src);

void changeDir(char *buffer);

int special(char *buffer);

void env(void);

void appendPath(char *token, char *str, char *path, char *first);

char *print_int(va_list args);

int print_buffer(char buffer[]);

char print_char(va_list args);

char *print_string(va_list args);

char *intToString(int num);

int _printf(const char *format, ...);

void add_to_buffer_string(char buffer[], char *str);

void add_to_buffer_char(char buffer[], char c);

int num_len(int x);

void exitShell(char *token);

void prompt(void);

char *_getline_fun(void);

void comment_handle(char *str);

char *whiteSpace_remover(char *str);

#endif
