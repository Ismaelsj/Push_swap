# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isidibe- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 13:39:55 by isidibe-          #+#    #+#              #
#    Updated: 2018/01/27 17:53:37 by isidibe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

SRC_C = $(SRCDIR)/checker.c\
$(SRCDIR)/ft_sort_tab.c\

SRC_P = $(SRCDIR)/push_swap.c\
$(SRCDIR)/ft_selection_sort.c\
$(SRCDIR)/ft_move_a.c\
$(SRCDIR)/ft_move_b.c\
$(SRCDIR)/ft_get_mediane.c\
$(SRCDIR)/ft_if_pile.c\
$(SRCDIR)/ft_sort_tab.c\
$(SRCDIR)/ft_mini_tool.c\
$(SRCDIR)/ft_mini_sort3.c\
$(SRCDIR)/ft_mini_sort5.c


SRC = $(SRCDIR)/double_op.c\
$(SRCDIR)/ft_doublons.c\
$(SRCDIR)/ft_error.c\
$(SRCDIR)/swap_and_push.c\
$(SRCDIR)/ft_tool1.c\
$(SRCDIR)/ft_tool2.c\
$(SRCDIR)/ft_newpile.c\
$(SRCDIR)/ft_atol.c\
$(SRCDIR)/ft_del_list.c\

INCLUDES = includes

OBJDIR = objects

SRCDIR_C = srcs_c

SRCDIR_P = srcs_p

SRCDIR = srcs

OBJ_C = $(SRC_C:$(SRCDIR)/%.c=%.o)

OBJ_P = $(SRC_P:$(SRCDIR)/%.c=%.o)

OBJ = $(SRC:$(SRCDIR)/%.c=%.o)

NAME_C = checker

NAME_P = push_swap

LIB = libft/libft.a

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJ_C) $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJ_C) $(OBJ) ./Libft/libft.a

$(NAME_P): $(OBJ_P) $(OBJ)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME_P) $(OBJ_P) $(OBJ) ./Libft/libft.a

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_P)
	@rm -f $(OBJ_C)
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_P)
	@rm -rf $(NAME_C)
	@make fclean -C ./libft

re: fclean all

%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $< $(CFLAGS) -I $(INCLUDES)
