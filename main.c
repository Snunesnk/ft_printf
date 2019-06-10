/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/10 21:03:18 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	double to_print;
	int test;
	char str[] = "Hello World!";

	(void)str;
	test = 42;
	to_print = 142.759;
	printf("vrai printf : |%#+-7.1f|\n", to_print);
	ft_printf("faux printf : |%#+-7.1f|\n", to_print);
	return (0);
}
