/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/05 03:55:20 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	float to_print;
	int test;

	test = 42;
	to_print = 42.759;
	printf("vrai printf : |%17.x| \n", test);
	ft_printf("faux printf : |%17.x| et : %.10f, ainsi que : %d\n", test, to_print, test);
	return (0);
}
