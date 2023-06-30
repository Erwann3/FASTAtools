/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** determine_display.c
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/options.h"

void determine_display(char ***buffer, options_t options)
{
    char **kmers = NULL;
    int count = 0;

    switch (options.argument) {
        case 1:
            display_buffer(buffer);
            break;
        case 2:
            rna_buffer(buffer);
            display_buffer(buffer);
            break;
        case 3:
            reverse_complement(buffer);
            display_buffer(buffer);
            break;
        case 4:
            count = print_kmers(buffer, &kmers, options.k_mers);
            cleanup_kmers(kmers, count);
            break;
    }
}

static void buffer_cleanup(am_acids_t am_acids)
{
    for (int i = 0; i < am_acids.count; i++)
        free(am_acids.sequences[i]);
    free(am_acids.sequences);
}

void determine_display2(char ***buffer, int buffer_count, options_t options)
{
    am_acids_t am_acids;
    am_acids.count = 0;
    am_acids.sequences = NULL;

    switch (options.argument) {
        case 5:
            am_acids.sequences =
                print_coding_sequences(buffer, &am_acids,
                    true, buffer_count);
            break;
        case 6:
            am_acids.sequences =
                print_coding_sequences(buffer, &am_acids,
                    false, buffer_count);
            if (am_acids.sequences == NULL)
                return;
            translate_and_print_aa(am_acids.sequences, am_acids.count);
            buffer_cleanup(am_acids);
            break;
    }
}

static int determine_line(char ***buffer, int buffer_count, int index)
{
    for (int i = 0; i < buffer_count; i++) {
        if ((*buffer)[i][0] != '>' && i != index)
            return i;
    }
    return -1;
}

void determine_display3(char ***buffer, int buffer_count, options_t options)
{
    int first_line = 0;
    int second_line = 0;

    switch (options.argument) {
        case 7:
            first_line = determine_line(buffer, buffer_count, -1);
            second_line = determine_line(buffer, buffer_count,
                first_line);
            if (first_line == -1 || second_line == -1)
                return;
            needleman_wunsch((*buffer)[first_line], (*buffer)[second_line]);
            break;
    }
}
