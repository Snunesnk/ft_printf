/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 15:40:02 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

// c = (char)0;

int main(void)
{
	double data;

	data = 1.7e-150;
	printf("vrai printf :\n");
	printf(", ret = %d\n", printf("^.^/%14.274f^.^/", data));
	printf("\nfaux printf :\n");
	printf(", ret = %d\n", ft_printf("^.^/%14.274f^.^/", data));
}
