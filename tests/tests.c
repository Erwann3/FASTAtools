/*
** EPITECH PROJECT, 2022
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** tests.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern char *translate_sequence(char *sequence, int sequence_length);
extern void translate_and_print_aa(char **sequences, int buffer_count);

Test(translate_sequence, valid_sequence) {
    char sequence[] = "AAA";
    char *result = translate_sequence(sequence, strlen(sequence));

    cr_assert_str_eq(result, "K", "Expected 'K' but got '%s'", result);
    free(result);
}

Test(translate_sequence, sequence_not_multiple_of_three) {
    char sequence[] = "AA";
    char *result = translate_sequence(sequence, strlen(sequence));

    cr_assert_str_eq(result, "", "Expected empty string but got '%s'", result);
    free(result);
}

Test(translate_sequence, invalid_codon) {
    char sequence[] = "XXX";
    char *result = translate_sequence(sequence, strlen(sequence));

    cr_assert_null(result, "Expected NULL for invalid codon");
    free(result);
}

Test(translate_and_print_aa, no_sequences) {
    char **sequences = NULL;

    cr_redirect_stdout();
    translate_and_print_aa(sequences, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("", "Expected no output for no sequences");
}

Test(translate_and_print_aa, valid_sequences) {
    char *sequences[] = {"AAA", "AGA", "GGG"};

    cr_redirect_stdout();
    translate_and_print_aa(sequences, 3);
    fflush(stdout);
    cr_assert_stdout_eq_str("K\nR\nG\n",
        "Expected 'K\nR\nG\n' but got different output");
}
