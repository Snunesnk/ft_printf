/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/09/10 18:27:24 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	main(void)
{

	long double data =  42.42;

	(void)data;
	int ret = printf("vrai |%Lf|\n", data); printf("ret = %d\n", ret);
	int ret2 = ft_printf("faux |%Lf|\n", data); printf("ret 2 = %d\n", ret2);
	printf("---------------------------------------\n");
	ret = printf("vrai |%Lf|\n", (long double)data); printf("ret = %d\n", ret);
	ret2 = ft_printf("faux |%Lf|\n", (long double)data); printf("ret 2 = %d\n", ret2);
}
