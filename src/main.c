/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/17 12:36:46 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

// c = (char)0;

int main(void)
{
	printf("vrai printf :\n");
	printf("ret = %d\n", printf("^.^/%2.19f^.^/", 0.0/0.0));
	printf("\nfaux printf :\n");
	printf("ret = %d\n", ft_printf("^.^/%2.19f^.^/", 0.0/0.0));
}
