# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunes <snunes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 12:37:58 by snunes            #+#    #+#              #
#    Updated: 2019/06/22 18:37:26 by snunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
SRC_PATH = src
SRC_NAME = 	ft_printf.c \
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
			BigInt.c \
			print_csp.c \
			handle_flags.c
OBJ_PATH = obj
I_PATH = include
HEADERS = ft_printf.h libft.h
OBJ_NAME = $(SRC_NAME:.c=.o)
CCFLAGS = -Wall -Wextra -Werror
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
HEADER = $(addprefix $(I_PATH)/,$(HEADERS))

CLINE = \033[K
CLEAR = \033[0m
GREEN = \033[32m
BYELLOW = \033[33;1m
BRED = \033[31m

TEST_SRCS = unit-tests/main.c \
			unit-tests/char_test.c

.PHONY : all, clean, fclean, re, help, norme

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
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEADER)
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

test : all 
	@$(CC) $(TEST_SRCS) -L. -lftprintf -I unit-tests/
	@echo "$(BRED)Executable created$(CLEAR)"
