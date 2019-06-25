/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/25 20:06:57 by snunes           ###   ########.fr       */
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

	data = 0.0;
	printf("vrai printf :\n");
	printf(", ret = %d\n", printf("%26.9f", data));
	printf("\nfaux printf :\n");
	printf(", ret = %d\n", ft_printf("%26.9f", data));
}
