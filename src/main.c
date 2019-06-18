/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/18 20:30:18 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

// c = (char)0;

int main(void)
{
	double x1=(double)0x7ff0000000000000;

	printf("vrai printf :\n");
	printf("ret = %d\n", printf("%+u", 4294967295));
	printf("\nfaux printf :\n");
	printf("ret = %d\n", ft_printf("%+u", 4294967295));
}
