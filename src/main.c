/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 16:43:15 by snunes           ###   ########.fr       */
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
	printf("Vrai printf :\n");
	printf("\\!/%32lc\\!/\n", (char)0);
	printf("ft_printf :\n");
	ft_printf("\\!/%32lc\\!/\n", (char)0);
	return (0);
}
