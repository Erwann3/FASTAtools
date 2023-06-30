/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** coding_sequences.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

const char *start_codon = "ATG";
const char *stop_codons[] = {"TAA", "TAG", "TGA", NULL};

static int is_stop_codon(char *codon)
{
    for (int i = 0; stop_codons[i] != NULL; i++) {
        if (strncmp(codon, stop_codons[i], 3) == 0)
            return 1;
    }
    return 0;
}

static void find_and_store_sequence(char *sequence, size_t i,
    char ***coding_sequences, int *coding_sequences_count)
{
    char *start = sequence + i;
    char *stop = NULL;
    char **new_sequences = NULL;

    for (size_t k = i; k < strlen(sequence); k += 3) {
        if (is_stop_codon(sequence + k)) {
            stop = sequence + k;
            break;
        }
    }
    if (stop) {
        new_sequences = realloc(*coding_sequences,
            (*coding_sequences_count + 1) * sizeof(char *));
        if (new_sequences != NULL) {
            *coding_sequences = new_sequences;
            (*coding_sequences)[*coding_sequences_count] =
                strndup(start, stop - start);
            (*coding_sequences_count)++;
        }
    }
}

static void process_sequence(char *sequence, size_t start_index,
    char ***coding_sequences, int *coding_sequences_count)
{
    if (strncmp(sequence + start_index, start_codon, 3) == 0) {
        find_and_store_sequence(sequence, start_index,
            coding_sequences, coding_sequences_count);
    }
}

void process_buffer(char *buffer, am_acids_t *am_acids)
{
    char *reverse_complement = generate_reverse_complement(buffer);

    if (reverse_complement == NULL)
        return;
    for (int offset = 0; offset < 3; offset++) {
        for (size_t i = offset; i < strlen(buffer); i += 3)
            process_sequence(buffer, i, &am_acids->sequences,
                &am_acids->count);
        for (size_t i = offset; i < strlen(reverse_complement); i += 3)
            process_sequence(reverse_complement, i,
                &am_acids->sequences, &am_acids->count);
    }
    free(reverse_complement);
}

char **print_coding_sequences(char ***buffer, am_acids_t *am_acids,
    bool display, int count)
{
    for (int j = 0; j < count; j++) {
        if ((*buffer)[j][0] == '>')
            continue;
        process_buffer((*buffer)[j], am_acids);
    }
    qsort(am_acids->sequences, am_acids->count,
        sizeof(char *), compare_strings);
    if (display) {
        for (int i = 0; i < am_acids->count; i++) {
            printf("%s\n", am_acids->sequences[i]);
            free(am_acids->sequences[i]);
        }
        free(am_acids->sequences);
    }
    return am_acids->sequences;
}
