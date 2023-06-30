/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** reverse_complement.c
*/

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <string.h>

void reverse_str(char *str)
{
    char *start = str;
    char *end = start + strlen(str) - 1;
    char temp;

    if (str == 0)
        return;
    if (*str == 0)
        return;
    while (end > start) {
        temp = *start;
        *start = *end;
        *end = temp;
        ++start;
        --end;
    }
}

static void update_char_buffer(char ***buffer, int i)
{
    for (int j = 0; (*buffer)[i][j] != 0; j++) {
        if ((*buffer)[i][j] == 'A') {
            (*buffer)[i][j] = 'T';
            continue;
        }
        if ((*buffer)[i][j] == 'T') {
            (*buffer)[i][j] = 'A';
            continue;
        }
        if ((*buffer)[i][j] == 'G') {
            (*buffer)[i][j] = 'C';
            continue;
        }
        if ((*buffer)[i][j] == 'C') {
            (*buffer)[i][j] = 'G';
            continue;
        }
    }
}

static void update_buffer(char ***buffer, int i)
{
    reverse_str((*buffer)[i]);
    update_char_buffer(buffer, i);
}

void reverse_complement(char ***buffer)
{
    for (int i = 0; (*buffer)[i] != NULL; i++) {
        if ((*buffer)[i][0] != '>' && (*buffer)[i][1] != '>')
            update_buffer(buffer, i);
    }
}
