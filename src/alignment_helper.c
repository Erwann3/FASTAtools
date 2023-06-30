/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** alignment_helper.c
*/

#include <stdlib.h>
#include "../include/alignment_data.h"

static int max(int a, int b, int c)
{
    int max = (a > b) ? a : b;

    return (max > c) ? max : c;
}

static int score(char a, char b)
{
    if (a == b)
        return 1;
    return -1;
}

int **allocate_matrix(int len1, int len2)
{
    int **S = (int **) malloc((len1 + 1) * sizeof(int *));

    if (S == NULL)
        return NULL;
    for (int i = 0; i <= len1; i++) {
        S[i] = (int *) malloc((len2 + 1) * sizeof(int));
        if (S[i] != NULL)
            continue;
        for (int k = 0; k < i; k++)
            free(S[k]);
        free(S);
        return NULL;
    }
    return S;
}

void initialize_matrix(int **S, int len1, int len2)
{
    for (int i = 0; i <= len1; i++)
        S[i][0] = -i;
    for (int j = 0; j <= len2; j++)
        S[0][j] = -j;
}

void fill_matrix(alignment_data_t *data)
{
    int match = 0;
    int delete = 0;
    int insert = 0;

    for (int i = 1; i <= data->len1; i++) {
        for (int j = 1; j <= data->len2; j++) {
            match = data->matrix[i - 1][j - 1] +
                score(data->seq1[i - 1], data->seq2[j - 1]);
            delete = data->matrix[i - 1][j] - 1;
            insert = data->matrix[i][j - 1] - 1;
            data->matrix[i][j] = max(match, delete, insert);
        }
    }
}
