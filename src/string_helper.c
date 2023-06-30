/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** string_helper.c
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my.h"

bool is_line_empty(const char *line)
{
    for (int i = 0; line[i] != 0; i++) {
        if (!isspace(line[i]))
            return false;
    }
    return true;
}

char *satanize_line(const char *line)
{
    const char *allowed_chars = "AaTtGgCcNn";
    int len = strlen(line);
    char *new_line = (char *)malloc(sizeof(char) * (len + 1));

    if (new_line == NULL)
        return NULL;
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (strchr(allowed_chars, line[i]))
            new_line[j++] = toupper(line[i]);
    }
    new_line[j] = 0;
    return new_line;
}

char *remove_newline(const char *str)
{
    size_t len = strlen(str);
    char *new_str = malloc(len + 1);
    size_t j = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] != '\n') {
            new_str[j] = str[i];
            j++;
        }
    }
    new_str[j] = 0;
    return new_str;
}

int compare_strings(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
