/*
** EPITECH PROJECT, 2023
** B-SYN-200-NAN-2-1-FASTAtools-erwann.tanguy [WSL: Ubuntu]
** File description:
** parse.c
*/

#include <stdlib.h>
#include <string.h>
#include "../include/options.h"
#include "../include/my.h"

static int parse_kmers(char *arg)
{
    int result = atoi(arg);

    return result == 0 ? -1 : result;
}

options_t parse_options(char **argv, int argc, options_t options)
{
    int result = 0;
    options.k_mers = -1;

    if (strcmp(argv[1], "-h") == 0)
        display_help();
    result = atoi(argv[1]);
    if (result == 0)
        return options;
    options.argument = result;
    if (options.argument == 4 && argc > 2)
        options.k_mers = parse_kmers(argv[2]);
    return options;
}
