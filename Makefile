# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: groman-l <groman-l@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 14:47:35 by groman-l          #+#    #+#              #
#    Updated: 2023/08/10 12:51:40 by groman-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VARIABLES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME = push_swap
CC = gcc
RM = rm -rf
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror -g

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SORUCES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRC = 		check.c push_swap.c init.c push.c utils.c swap.c rotate.c rev_rotate.c sorting.c tiny_sort.c
LIBFT = ./libft/
L_SRC = ./src
L_LIB = ./libft/libft.a
INC =   -I ./inc/\
        -I ./libft/\

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DIRECTORIES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
D_OBJ = $(L_SRC)/obj
OBJ = $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAKE RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
all: dir $(NAME)

-include $(DEP)

dir:
	make -C  $(LIBFT) --no-print-directory
	mkdir -p $(D_OBJ)

$(D_OBJ)/%.o: $(L_SRC)/%.c
	$(CC) -MMD $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(L_LIB) -o $(NAME) $(INC)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~futura no barra de carga~~~~~~~~~~~~~~~~~~~#

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CLEAN~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
.PHONY: clean fclean re

fclean: clean
	$(RM) $(NAME) $(NAME)
	make fclean -C $(LIBFT) --no-print-directory

clean:
	$(RM) $(D_OBJ)
	make clean -C $(LIBFT) --no-print-directory

re: fclean all
.SILENT: