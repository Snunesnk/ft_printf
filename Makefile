# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunes <snunes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 12:37:58 by snunes            #+#    #+#              #
#    Updated: 2019/06/27 21:20:52 by snunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
VPATH = src/ft_printf:src/libft:src/output:src/conversions:src/double:include:

SRC = 		ft_printf.c \
			lst_func_1.c \
			lst_func_2.c \
			lst_func_3.c \
			get_arg.c \
			print_multi.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_putstr.c \
			ft_strlen.c \
		   	ft_isspace.c \
			ft_memalloc.c \
			ft_putchar.c \
		   	ft_bzero.c \
			ft_strcat.c \
			ft_strcpy.c \
			reset_flags.c \
			ft_nblen.c \
			deal_wdouble.c \
			exept_double.c \
			big_int.c \
			print_csp.c \
			handle_flags.c \
			deal_w_l_double.c \
			handle_colors.c \
			ft_isalpha.c \
			ft_strequ.c
OBJ_PATH = obj
I_PATH = include
HEADER = ft_printf.h libft.h
OBJ_NAME = $(SRC:.c=.o)
CCFLAGS = -Wall -Wextra -Werror
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CLINE = \033[K
CLEAR = \033[0m
GREEN = \033[32m
BYELLOW = \033[33;1m
BRED = \033[31m

TEST_SRCS = unit-tests/main.c \
			unit-tests/char_test.c

.PHONY : all, clean, fclean, re, help, norme, exec

## all		: compile et cree l'executable
all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(BYELLOW)Generating $(BRED)$@$(CLEAR)"
	@ar -rcs $@ $^
	@ranlib $@
	@echo "$(GREEN)[DONE]$(CLEAR)"

exec : src/main.c $(NAME)
	@echo "$(BYELLOW)Creating executable file$(CLEAR)"
	@gcc -g src/main.c -o exec -I include -L. -lftprintf

## objet		: verifie que les objets et le header soient a jour
$(OBJ_PATH)/%.o : %.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true 
	@$(CC) $(CCFLAGS) -I $(I_PATH) -o $@ -c $< 
	@echo "$(GREEN)[OK]\t$(BYELLOW)Compiling$(CLEAR) $<"

## clean		: efface tout les binaires
clean :
	@echo "$(BRED)Cleaning all binaries$(CLEAR)"
	@rm -f $(OBJ)
	@echo "$(BRED)Removing binaries folder$(CLEAR)"
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

## fclean		: efface les binaires ainsi que l'executable
fclean : clean
	@echo "$(BRED)Deleting $(NAME)$(CLEAR)"
	@rm -f $(NAME)

## re		: lance la regle "fclean", puis la regle "all"
re : fclean all

## norme		: verifie la norme du projet
norme :
	@norminette $(SRC)
	@norminette $(HEADER)

## help		: affiche les options disponibles et leurs utilitees
help : Makefile
	@sed -n 's/^##//p' $<
