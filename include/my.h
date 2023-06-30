/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdbool.h>
    #include "options.h"
    #include "amino_acids.h"
    #include "alignment_data.h"

void display_help(void);
options_t parse_options(char **argv, int argc, options_t options);
int read_input(char ***buffer);
void clean_buffer(char **buffer, int count);
void display_buffer(char ***buffer);
bool is_line_empty(const char *line);
char *satanize_line(const char *line);
char *remove_newline(const char *str);
void determine_display(char ***buffer, options_t options);
void determine_display2(char ***buffer, int buffer_count, options_t options);
void rna_buffer(char ***buffer);
void reverse_complement(char ***buffer);
int print_kmers(char ***buffer, char ***kmers, int k);
void cleanup_kmers(char **kmers, int count);
char **print_coding_sequences(char ***buffer,
    am_acids_t *am_acids, bool display, int count);
int compare_strings(const void *a, const void *b);
void translate_and_print_aa(char **sequences, int buffer_count);
int amino_acids_compare(const void *a, const void *b);
void needleman_wunsch(char *seq1, char *seq2);
void determine_display3(char ***buffer, int buffer_count, options_t options);
char *generate_reverse_complement(char *sequence);
void fill_matrix(alignment_data_t *data);
void initialize_matrix(int **S, int len1, int len2);
int **allocate_matrix(int len1, int len2);

#endif
