# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snunes <snunes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 12:37:58 by snunes            #+#    #+#              #
#    Updated: 2019/09/10 18:28:11 by snunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
VPATH = src:include:libft

SRC = 		ft_printf.c \
			lst_func_1.c \
			lst_func_2.c \
			lst_func_3.c \
			get_flags.c \
			print_multi.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_strlen.c \
		   	ft_isspace.c \
			ft_memalloc.c \
		   	ft_bzero.c \
			ft_strcat.c \
			ft_strcpy.c \
			arrange_flags.c \
			ft_nblen.c \
			deal_wdouble.c \
			exept_double.c \
			big_int.c \
			print_csp.c \
			handle_flags.c \
			deal_w_l_double.c \
			handle_colors.c \
			ft_isalpha.c \
			ft_strequ.c \
			init_arrays.c \
			ft_dprintf.c
OBJ_PATH = obj
I_PATH = include
HEADER = ft_printf.h libft.h
OBJ_NAME = $(SRC:.c=.o)
CCFLAGS = -Wall -Wextra -Werror -ggdb3
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LCLEAR = \033[2K
CURSOR = \033[1A
CLINE = \033[K
CLEAR = \033[0m
GREEN = \033[32m
BYELLOW = \033[33;1m
BRED = \033[31m
BWHITE = \033[37;1m
BCYAN = \033[36;1m

.PHONY : all, clean, fclean, re, help, norme, exec

## all		: compile et cree l'executable
all : $(NAME)

$(NAME) : $(OBJ)
	@ar -rcs $@ $^
	@ranlib $@
	@echo "$(LCLEAR)$(BCYAN)$@$(BWHITE) => $(BGREEN)[done]$(CLEAR)"

exec : main.c $(NAME)
	@echo "$(LCLEAR)$(BCYAN)$@$(BWHITE) => $(BGREEN)[done]$(CLEAR)"
	@gcc -g main.c -o exec -I include -L. -lftprintf

## objet		: verifie que les objets et le header soient a jour
$(OBJ_PATH)/%.o : %.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true 
	@$(CC) $(CCFLAGS) -I $(I_PATH) -o $@ -c $< 
	@echo "$(LCLEAR)$(BWHITE)[Compiling] =>$(CLEAR) $<$(CLINE)$(CURSOR)"

## clean		: efface tout les binaires
clean :
	@echo "$(RED)Deleting $(NAME) obj$(CLEAR)$(CURSOR)"
	@rm -f $(OBJ)
	@echo "$(LCLEAR)$(RED)Deleting $(NAME) obj folder$(CLEAR)$(CURSOR)" 
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

## fclean		: efface les binaires ainsi que l'executable
fclean : clean
	@echo "$(LCLEAR)$(RED)Deleting $(NAME)$(CLEAR)"
	@rm -f $(NAME)

## re		: lance la regle "fclean", puis la regle "all"
re : fclean all

## norme		: verifie la norme du projet
norme :
	@norminette $(SRC_PATH) | grep -B1 --colour=auto "Error" || true
	@norminette $(I_PATH) | grep -B1 --colour=auto "Error" || true
	@cd libft && $(MAKE) $@

## help		: affiche les options disponibles et leurs utilitees
help : Makefile
	@sed -n 's/^##//p' $<
