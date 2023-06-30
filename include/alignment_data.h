/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** alignment_data.h
*/

#ifndef ALIGNMENT_DATA_H
    #define ALIGNMENT_DATA_H

typedef struct alignment_data_s {
    char *seq1;
    char *seq2;
    int **matrix;
    int len1;
    int len2;
} alignment_data_t;

#endif
