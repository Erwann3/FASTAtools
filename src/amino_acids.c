/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** amino_acids.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

static char *codon_array[][8] = {
    {"GCT", "GCC", "GCA", "GCG", "A", 0},
    {"TGT", "TGC", "C", 0},
    {"GAT", "GAC", "D", 0},
    {"GAA", "GAG", "E", 0},
    {"TTT", "TTC", "F", 0},
    {"GGT", "GGC", "GGA", "GGG", "G", 0},
    {"CAT", "CAC", "H", 0},
    {"ATT", "ATC", "ATA", "I", 0},
    {"AAA", "AAG", "K", 0},
    {"TTA", "TTG", "CTT", "CTC", "CTA", "CTG", "L", 0},
    {"ATG", "M", 0},
    {"AAT", "AAC", "N", 0},
    {"CCT", "CCC", "CCA", "CCG", "P", 0},
    {"CAA", "CAG", "Q", 0},
    {"AGA", "AGG", "CGT", "CGC", "CGA", "CGG", "R", 0},
    {"TCT", "TCC", "TCA", "TCG", "AGT", "AGC", "S", 0},
    {"ACT", "ACC", "ACA", "ACG", "T", 0},
    {"GTT", "GTC", "GTA", "GTG", "V", 0},
    {"TGG", "W", 0},
    {"TAT", "TAC", "Y", 0},
    {NULL}
};

void get_index(int i, int *k)
{
    while (codon_array[i][*k] != NULL)
        (*k)++;
}

char return_array(char *codon, int i)
{
    int k = 0;

    for (int j = 0; codon_array[i][j] != NULL; j++) {
        k = 0;
        if (strcmp(codon, codon_array[i][j]) == 0) {
            get_index(i, &k);
            return codon_array[i][k - 1][0];
        }
    }
    return 0;
}

char find_char_by_codon_array(char *codon)
{
    char result = 0;

    for (int i = 0; codon_array[i][0] != NULL; i++) {
        result = return_array(codon, i);
        if (result != 0)
            return result;
    }
    return 0;
}

char *translate_sequence(char *sequence, int sequence_length)
{
    char codon[4];
    char *aa_sequence = (char *) malloc((sequence_length / 3) + 1);
    int aa_index = 0;

    if (!aa_sequence)
        return NULL;
    memset(codon, 0, sizeof(codon));
    for (int i = 0; i < sequence_length; i += 3) {
        if (i + 3 > sequence_length)
            break;
        strncpy(codon, &sequence[i], 3);
        codon[3] = 0;
        aa_sequence[aa_index++] = find_char_by_codon_array(codon);
    }
    aa_sequence[aa_index] = 0;
    return aa_sequence;
}

void translate_and_print_aa(char **sequences, int buffer_count)
{
    char **aa_sequences = (char **) malloc(sizeof(char *) * buffer_count);
    if (!aa_sequences)
        return;

    for (int i = 0; i < buffer_count; i++) {
        if (sequences[i][0] == '>')
            continue;
        int sequence_length = strlen(sequences[i]);
        aa_sequences[i] = translate_sequence(sequences[i], sequence_length);
        if (!aa_sequences[i])
            return;
    }
    qsort(aa_sequences, buffer_count, sizeof(aa_sequences[0]),
        compare_strings);
    for (int i = 0; i < buffer_count; i++) {
        printf("%s\n", aa_sequences[i]);
        free(aa_sequences[i]);
    }
    free(aa_sequences);
}
