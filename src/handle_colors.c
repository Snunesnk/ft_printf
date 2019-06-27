/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:28:40 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 15:08:22 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_H_color(char color[10])
{
	int			i;
	static char *colours[18] = {"H_black\0", "\033[7;30m\0", "H_red\0",
		"\033[7;31m\0",	"H_green\0", "\033[7;32m\0", "H_yellow\0", 
		"\033[7;33m\0", "H_blue\0",	"\033[7;34m\0", "H_purple\0", 
		"\033[7;35m\0", "H_cyan\0", "\033[7;36m\0",	"H_gray\0", "\033[7;37m\0",
	   	"eoc\0", "\033[0m\0"};
	
	i = 0;
	while (i < 18 && !ft_strequ(color, colours[i]))
		i += 2;
	if (i < 17)
		return (write(1, colours[i + 1], sizeof(colours[i + 1]) - 1));
	return (-1);
}

int	put_U_color(char color[10])
{
	int			i;
	static char *colours[18] = {"U_black\0", "\033[4;30m\0", "U_red\0",
		"\033[4;31m\0",	"U_green\0", "\033[4;32m\0", "U_yellow\0", 
		"\033[4;33m\0", "U_blue\0",	"\033[4;34m\0", "U_purple\0", 
		"\033[4;35m\0", "U_cyan\0", "\033[4;36m\0",	"U_gray\0", "\033[4;37m\0",
	   	"eoc\0", "\033[0m\0"};
	
	i = 0;
	while (i < 18 && !ft_strequ(color, colours[i]))
		i += 2;
	if (i < 17)
		return (write(1, colours[i + 1], sizeof(colours[i + 1]) - 1));
	return (-1);
}

int	put_B_color(char color[10])
{
	int			i;
	static char *colours[18] = {"B_black\0", "\033[1;30m\0", "B_red\0",
		"\033[1;31m\0",	"B_green\0", "\033[1;32m\0", "B_yellow\0", 
		"\033[1;33m\0", "B_blue\0",	"\033[1;34m\0", "B_purple\0", 
		"\033[1;35m\0", "B_cyan\0", "\033[1;36m\0",	"B_gray\0", "\033[1;37m\0",
	   	"eoc\0", "\033[0m\0"};
	
	i = 0;
	while (i < 18 && !ft_strequ(color, colours[i]))
		i += 2;
	if (i < 17)
		return (write(1, colours[i + 1], sizeof(colours[i + 1]) - 1));
	return (-1);
}

int	put_color(char color[8])
{
	int			i;
	static char *colours[18] = {"black\0", "\033[30m\0", "red\0", "\033[31m\0",
	   	"green\0", "\033[32m\0", "yellow\0", "\033[33m\0", "blue\0",
		"\033[34m\0", "purple\0", "\033[35m\0", "cyan\0", "\033[36m\0",
		"gray\0", "\033[37m\0", "eoc\0", "\033[0m\0"};
	
	i = 0;
	while (i < 18 && !ft_strequ(color, colours[i]))
		i += 2;
	if (i < 17)
		return (write(1, colours[i + 1], sizeof(colours[i + 1]) - 1));
	return (-1);
}

int	handle_colors(t_flags *flag, const char *str)
{
	int		pos;
	int		ret;
	int		i;
	char	color[10];

	i = 0;
	pos = flag->spos + 1;
	ret = pos - 1;
	ft_bzero(color, 10);
	while (str[pos] != '}' && i < 8)
	{
		color[i++] = str[pos++];
		if (str[pos] != '}' && !ft_isalpha(str[pos]) && str[pos] != '_')
			return (ret);
	}
	if (color[0] == 'H' && put_H_color(color) > 0)
		flag->color = 1;
	else if (color[0] == 'U' && put_U_color(color) > 0)
		flag->color = 1;
	else if (color[0] == 'B' && put_B_color(color) > 0)
		flag->color = 1;
	else if (put_color(color) == -1)
		return (ret);
	flag->color = 1;
	return (pos + 1);
}
