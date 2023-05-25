#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <limits.h>
#include <ctype.h>

int handle_spec_var(char **args, int i);
int buildincmd(char **args, char *str);
int handle_sep_ope(char *line, char **argv, char **env);
int logicope(char *line, char **argv, char **env);
int logic__operator(char *line, char **argv, char **env);
int handlesep(char *line, char **argv, char **env);

char *_memset(void *s, char b, unsigned int n);
char *_strtok(char *str, char *delim);
int _strstr(char *haystack, char *needle);
void hashtag_handle(char *buff);
void resizememory(char **ptr, size_t *n, ssize_t num);

int execute(char **args, char **argv, char **env);
int numlen(unsigned int num);
char *get_executable_name(char **argv);
int cdir(char *path, char **args);
void reverse(char *arr, int len);
char *utoa(unsigned int num);
void reverse_chars(char *line, ssize_t num_chars);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
extern char **environ;
char **tokenizer(char *str);
int count_args(char *input);
char *getfullpath(char *str, char *Path);
int search_executable(char **args, char **argv, char **env);
char *get_env_var(char *name);
int exit_shell(char **args, char *str);
void envr(void);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int set_env(char **args);
int unset_env(char **args);
void free_tokens(char **tokens);
void _eof(int len, char *buffer);
/*#define BUFFER_SIZE 4096*/
#endif
