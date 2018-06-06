#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlyubich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 17:12:34 by dlyubich          #+#    #+#              #
#    Updated: 2018/02/04 13:04:25 by dlyubich         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

BLUE = echo "\033[0;36m"
RED = echo "\033[0;34m"
GREEN = echo "\033[0;32m"
END = echo "\033[0m"

NAME_PUSH = push_swap
NAME_CHECKER = checker

FLAGS = -Wall -Wextra -Werror

SRC_PUSH = ft_push_swap.c \
			ft_sort_trio_a.c \
			ft_sort_trio_b.c \
			ft_sort.c \
			ft_instructions.c \
			ft_instructions2.c \
			ft_short_instructions.c \
			ft_help.c \
			ft_more_instructions.c \
			check_input.c \
			ft_optimus.c \
			operations.c \
			optimus_helper.c 
OBJ_PUSH = $(SRC_PUSH:.c=.o)
GCFLAGS_PUSH = -I -I./libft/

SRC_CHECKER = ft_checker.c \
				ft_instructions.c \
				ft_instructions2.c \
				ft_help.c \
				ft_short_instructions.c \
				ft_more_instructions.c
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
GCFLAGS_CHECKER = -I -I./libft/

LIBFT = libft/libft.a

all: $(NAME_PUSH) $(NAME_CHECKER)

$(NAME_PUSH): $(OBJ_PUSH)
	@echo "$$($(BLUE))PUSH_SWAP : Sources compiling...$$($(END))"
	@make -C libft/
	-gcc $(FLAGS) $(GCFLAGS_PUSH) -o $@ $(OBJ_PUSH) $(LIBFT)
	@echo "$$($(GREEN))PUSH_SWAP : compile with SUCCESS!$$($(END))"

$(NAME_CHECKER): $(OBJ_CHECKER)
	@echo "$$($(BLUE))CHECKER : Sources compiling...$$($(END))"
	-gcc $(FLAGS) $(GCFLAGS_CHECKER) -o $@ $(OBJ_CHECKER) $(LIBFT)
	@echo "$$($(GREEN))CHECKER : compile with SUCCESS !$$($(END))"

$(OBJ_PATH_P)%.o: $(SRC_PATH_P)%.c
	-gcc $(FLAGS) $(GCFLAGS_PUSH) -o $@ -c $<

$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	-gcc $(FLAGS) $(GCFLAGS_CHECKER) -o $@ -c $<

random:	ft_random.o libft/libft.a
	-gcc $(FLAGS) ft_random.o $(LIBFT) -o random
	@echo "$$($(GREEN))RANDOM : compile with SUCCESS !$$($(END))" 

libft/libft.a :
	@make -C libft

ft_random.o :
	-gcc $(FLAGS) -c ft_random.c

clean:
	@make -C libft/ clean
	rm -f $(OBJ_PUSH)
	rm -f $(OBJ_CHECKER)
	rm -f ft_random.o
	@echo "$$($(RED))Objects removed...$$($(END))"

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME_PUSH) $(NAME_CHECKER) random
	@echo "$$($(RED))push_swap binary removed...$$($(END))"
	@echo "$$($(RED))checker binary removed...$$($(END))"

re: fclean all
	@make -C libft/ re
