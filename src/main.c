/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** main.c
*/

#include <stdlib.h>
#include "../include/my.h"

static void validate_options(options_t options)
{
    if (options.argument < 1 || options.argument > 7)
        exit(84);
    if (options.argument == 4 && options.k_mers < 0)
        exit(84);
}

int main(int argc, char **argv)
{
    options_t options;
    int buffer_size;
    char **buffer = NULL;

    if (argc > 3 || argc < 2)
        return 84;
    options = parse_options(argv, argc, options);
    validate_options(options);
    buffer_size = read_input(&buffer);
    determine_display(&buffer, options);
    determine_display2(&buffer, buffer_size, options);
    determine_display3(&buffer, buffer_size, options);
    clean_buffer(buffer, buffer_size);
}
