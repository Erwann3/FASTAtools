/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** requirement.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int is_alpha(char c)
{
    return (c >= '0' && c <= '9')
        || (c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z');
}

static char capitalize(char c, int *start)
{
    if (*start && c >= 'A' && c <= 'Z') {
        *start = 0;
        return c;
    }
    if (*start && c >= '0' && c <= '9') {
        *start = 0;
        return c;
    }
    if (*start && c >= 'a' && c <= 'z') {
        *start = 0;
        return c - 'a' + 'A';
    }
    if (!is_alpha(c))
        *start = 1;
    return c;
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;
    int start = 1;

    for (; str[i] != 0; i++)
        str[i] = capitalize(str[i], &start);
    return str;
}
