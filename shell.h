#ifndef MY__SHELL
#define MY__SHELL

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <linux/limits.h>
#include <errno.h>

#define BUFSIZE 1024

extern char **environ;

char *_strtok(char *stri, char *delim);
char *_strchr(char *str, char c);


char **tokenize_cmd(char *message);
void read_file(char *file_name, char **av);
int _atoi(char *s);
int exec_cmd(char **cmdline, char *line, char **av);
char *_getline(void);
void stringize(char *buffer);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int path_cmd(char **cmd);
char *build_ap(char *token, char *value);
int get_cmd(char **command);
char *path_to_cmd(char *token, char *value);
char *_getenv(char *name);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_memcpy(char *dest, char *src, unsigned int n);
int _isalpha(int c);
int print_env(char **cmd, int st);
void exec_file(char *buffer, FILE *fp, char **av);
void file_exit(char **command, char *buffer, FILE *fp);
char *_memset(char *s, char b, unsigned int n);



int _strlen(char *s);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
void printg(char *c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

#endif
