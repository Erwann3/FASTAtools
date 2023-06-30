/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** sequences_alignment.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my.h"

void needleman_wunsch(char *seq1, char *seq2)
{
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int **S = allocate_matrix(len1, len2);

    if (S == NULL)
        return;
    initialize_matrix(S, len1, len2);
    alignment_data_t data = {seq1, seq2, S, len1, len2};
    fill_matrix(&data);
    printf("%d\n", S[len1][len2]);
    for (int i = 0; i <= len1; i++)
        free(S[i]);
    free(S);
}
