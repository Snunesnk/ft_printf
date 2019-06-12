/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 20:24:48 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int main(void)
{
	float to_print;
	int test;
	char c;
	char str[] = "Hello World!";

	c = '\0';
	(void)str;
	test = 42;
	to_print = 142.759;
	printf("vrai printf : |%08i|\n", -71);
	ft_printf("faux printf : |%08i|\n", -71);
	return (0);
}
