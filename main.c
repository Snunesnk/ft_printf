/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 02:09:00 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	float to_print;
	int test;

	test = 42;
	to_print = 42.759;
	printf("vrai printf : %f \n", to_print);
	ft_printf("test avec float %f et : %.10f, ainsi que : %d\n", to_print, to_print, test);
	return (0);
}
