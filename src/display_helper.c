/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** display_helper.c
*/

#include <stdio.h>

static void update_buffer(char ***buffer, int i, int j)
{
    if ((*buffer)[i][j] == 'T')
        (*buffer)[i][j] = 'U';
}

void display_help(void)
{
    printf("USAGE\n");
    printf("\t./FASTAtools option [k]\n\n");
    printf("DESCRIPTION\n");
    printf("\toption 1: read FASTA from the standard input, write the DNA ");
    printf("sequences to the standard output\n");
    printf("\toption 2: read FASTA from the standard input, write the RNA ");
    printf("sequences to the standard output\n");
    printf("\toption 3: read FASTA from the standard input, write the ");
    printf("reverse complement to the standard output\n");
    printf("\toption 4: read FASTA from the standard input, write the k-mer ");
    printf("list to the standard output\n");
    printf("\toption 5: read FASTA from the standard input, write the ");
    printf("coding sequences list to the standard output\n");
    printf("\toption 6: read FASTA from the standard input, write the ");
    printf("amino acids list to the standard output\n");
    printf("\toption 7: read FASTA from the standard input containing ");
    printf("exactly 2 sequences, align them and write the result ");
    printf("to the standard output\n");
    printf("\tk: size of the k-mers for option 4");
}

void display_buffer(char ***buffer)
{
    for (int i = 0; (*buffer)[i] != NULL; i++) {
        printf("%s", (*buffer)[i]);
        printf("\n");
    }
}

void rna_buffer(char ***buffer)
{
    for (int i = 0; (*buffer)[i] != NULL; i++) {
        for (int j = 0; (*buffer)[i][j]; j++)
            update_buffer(buffer, i, j);
    }
}
