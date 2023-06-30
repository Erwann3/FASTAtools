/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** sort.c
*/

#include <string.h>

int amino_acids_compare(const void *a, const void *b)
{
    const char (*ia)[4] = a;
    const char (*ib)[4] = b;
    return strcmp(*ia, *ib);
}
