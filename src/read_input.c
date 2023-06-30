/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** read_input.c
*/

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/my.h"

static bool update_buffer(char ***buffer, size_t *buffer_size, char **line)
{
    char *tmp_line = NULL;
    char *tmp = NULL;
    char **tmp_again = NULL;

    (*line)[strcspn(*line, "\n")] = 0;
    if ((*line)[0] != '>')
        tmp_line = satanize_line(*line);
    if ((*line)[0] != '>' && *buffer_size > 0 &&
        (*buffer)[*buffer_size - 1][0] != '>') {
        tmp = realloc((*buffer)[*buffer_size - 1],
            strlen((*buffer)[*buffer_size - 1]) + strlen(tmp_line) + 2);
        (*buffer)[*buffer_size - 1] = tmp;
        strcat((*buffer)[*buffer_size - 1], tmp_line);
        return false;
    }
    (*buffer_size)++;
    tmp_again = realloc(*buffer, *buffer_size * sizeof(char *));
    *buffer = tmp_again;
    (*buffer)[*buffer_size - 1] = tmp_line != NULL ? tmp_line : strdup(*line);
    return true;
}

void clean_buffer(char **buffer, int count)
{
    for (int i = 0; i < count; i++)
        free(buffer[i]);
    free(buffer);
}

int read_input(char ***buffer)
{
    size_t buffer_size = 0;
    char *line = NULL;
    size_t len = 0;
    int read = 0;
    bool result = false;

    while ((read = getline(&line, &len, stdin)) != -1) {
        result = update_buffer(buffer, &buffer_size, &line);
        if (!result)
            continue;
    }
    free(line);
    return buffer_size;
}
