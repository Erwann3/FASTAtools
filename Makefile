##
## EPITECH PROJECT, 2023
## B-SYN-200-NAN-2-1-palindrome-erwann.tanguy [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

NAME = FASTAtools

RM = rm -f

CFLAGS = -Wall -Werror -Wextra -Iinclude

SRCS = src/main.c \
       src/display_helper.c \
       src/parse.c \
       src/read_input.c \
       src/string_helper.c \
       src/determine_display.c \
       src/reverse_complement.c \
       src/kmers.c \
       src/coding_sequence.c \
       src/amino_acids.c \
       src/sort.c \
       src/sequences_alignment.c \
       src/reverse_helper.c \
       src/alignment_helper.c

OBJS = $(SRCS:.c=.o)

SRC_TESTS = tests/tests.c

OBJ_TESTS = $(SRC_TESTS:.c=.o)

TEST_NAME = unit_tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

tests_run: CFLAGS += --coverage
tests_run: LDFLAGS += -lcriterion -lgcov
tests_run: $(OBJS) $(OBJ_TESTS)
		$(CC) -o $(TEST_NAME) $(OBJ) $(OBJ_TESTS) $(LDFLAGS)
		./$(TEST_NAME)

.PHONY: all clean fclean re tets_run
