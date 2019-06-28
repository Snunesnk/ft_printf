/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/28 12:54:19 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	main(void)
{
	double data;

	data = 1.42;
	printf("vrai printf :\n");
	printf(", ret = %d\n", printf("{%*3.*f}", 5, 8, data));
	printf("\nfaux printf :\n");
	printf(", ret = %d\n", ft_dprintf(1, "{{H_cyan}%*3.*f}", 5, 8, data));
}
