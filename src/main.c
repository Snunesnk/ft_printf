/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 20:26:31 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	long double data;

	data = 1.42;
	printf("vrai printf :\n");
	printf(", ret = %d\n", printf("{%Lf}", data));
	printf("\nfaux printf :\n");
	printf(", ret = %d\n", ft_printf("{%Lf}", data));
}
