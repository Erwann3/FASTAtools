/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** kmers.c
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

void cleanup_kmers(char **kmers, int count)
{
    qsort(kmers, count, sizeof(char *), compare_strings);
    for (int i = 0; i < count; i++)
        printf("%s\n", kmers[i]);
    free(kmers);
}

int is_unique(char **kmers, size_t kmers_count, char *kmer)
{
    if (kmers_count <= 0)
        return 1;
    for (size_t i = 0; i < kmers_count; i++) {
        if (strcmp(kmers[i], kmer) == 0)
            return 0;
    }
    return 1;
}

void add_kmer(char ***kmers, size_t *kmers_count, char *kmer)
{
    if (is_unique(*kmers, *kmers_count, kmer)) {
        *kmers = realloc(*kmers, ++(*kmers_count) * sizeof(char *));
        (*kmers)[*kmers_count - 1] = kmer;
    } else {
        free(kmer);
    }
}

int print_kmers(char ***buffer, char ***kmers, int k)
{
    size_t kmers_count = 0;
    char *kmer = NULL;

    for (size_t j = 0; (*buffer)[j] != NULL; j++) {
        if ((*buffer)[j][0] == '>')
            continue;
        for (size_t i = 0; i + k <= strlen((*buffer)[j]); i++) {
            kmer = strndup((*buffer)[j] + i, k);
            add_kmer(kmers, &kmers_count, kmer);
        }
    }
    qsort(*kmers, kmers_count - 1, sizeof(char *), compare_strings);
    return kmers_count;
}
