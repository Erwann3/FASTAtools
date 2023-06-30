/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** reverse_helper.c
*/

#include <string.h>
#include <stdlib.h>

static char *allocate_memory(char *sequence)
{
    size_t length = strlen(sequence);
    char *complement = malloc(length + 1);

    if (complement == NULL)
        return NULL;
    return complement;
}

static char assign_complement(char base)
{
    switch (base) {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
    }
    return 0;
}

static void build_reverse(char *sequence,
    char *complement)
{
    size_t length = strlen(sequence);

    for (size_t i = 0; i < length; i++)
        complement[length - 1 - i] = assign_complement(sequence[i]);
    complement[length] = 0;
}

char *generate_reverse_complement(char *sequence)
{
    char *reverse_complement = allocate_memory(sequence);

    if (reverse_complement == NULL)
        return NULL;
    build_reverse(sequence, reverse_complement);
    return reverse_complement;
}
