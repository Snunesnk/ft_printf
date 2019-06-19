/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:17:49 by snunes            #+#    #+#             */
/*   Updated: 2019/06/19 15:10:09 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	find_opt(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	int success;
	int fd;

	fd = open("result.txt", O_CREAT, O_RDWR);
	success = 0;
	if (ac == 1 || find_opt(av[1], 'c') == 1)
	{
		success += c_basic_tests(fd);
		success += c_width_tests(fd);
		success += c_big_test(fd);
		printf("\n\t\t\tYOU PASSED %d OF 11 CHAR TESTS\n\n", success);
	}
	else
		printf("No tests are available for that option yet\n");
	return (0);
}
