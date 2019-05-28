/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:15 by snunes            #+#    #+#             */
/*   Updated: 2019/05/28 19:53:50 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
//	char test[] = "Hello World!";
	char test2[] = "un deuxieme test";
	int to_print;
	void *ptr;

	ptr = &to_print;
	to_print = 42;
	ft_printf("voila testons tout ca ici\n");
	ft_printf("on a to_print = %c, et test2 = %s\n", to_print, test2);
	ft_printf("addresse du ptr : %p\n", ptr);
	return (0);
}
