/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:01:39 by snunes            #+#    #+#             */
/*   Updated: 2019/06/19 15:16:46 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	c_basic_tests(void)
{
	int ret_p;
	int ret_ft;
	int success;
	int failure;
	
	success = 0;
	failure = 0;
	printf("\033[33mBeginig of basic test :\033[0m\n\n");
	printf("Test 1 : %%c with arg = 'c'\nTrue printf :\n");
	ret_p = printf("----------<%c>----------", 'c');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%c>----------", 'c');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 2 %%c with arg = '*'\nTrue printf :\n");
	ret_p = printf("----------<%c>----------", '*');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%c>----------", '*');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 3 %%c with arg = '\\0'\nTrue printf :\n");
	ret_p = printf("----------<%c>----------", '\0');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%c>----------", '\0');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 4 : %%c with arg = '\\n'\nTrue printf :\n");
	ret_p = printf("----------<%c>----------", '\n');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%c>----------", '\n');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 5 : %%c with arg = (char)789\nTrue printf :\n");
	ret_p = printf("----------<%c>----------", (char)789);
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%c>----------", (char)789);
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("\033[36mEnd of basic test, got %d success and %d failure, on 5 tests\033[0m\n\n\n", success, failure);
	return (success);
}

int	c_width_tests(void)
{
	int ret_p;
	int ret_ft;
	int success;
	int failure;
	
	success = 0;
	failure = 0;
	printf("\033[33mBeginig of minus test :\033[0m\n\n");
	printf("Test 1 : %%9c arg = 'c'\nTrue printf :\n");
	ret_p = printf("----------<%9c>----------", 'c');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%9c>----------", 'c');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 2 : %%30c arg = '\\0'\nTrue printf :\n");
	ret_p = printf("----------<%30c>----------", '\0');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%30c>----------", '\0');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 3 : %%-9c arg = 'c'\nTrue printf :\n");
	ret_p = printf("----------<%-9c>----------", 'c');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%-9c>----------", 'c');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 4 : %%-c arg = '\\0'\nTrue printf :\n");
	ret_p = printf("----------<%-c>----------", '\0');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%-c>----------", '\0');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("Test 5 : %%-1c arg = 'c'\nTrue printf :\n");
	ret_p = printf("----------<%-1c>----------", 'c');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("----------<%-1c>----------", 'c');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
	{
		printf("\n\033[31m[KO]\033[0m, expected %d, got %d\n\n", ret_p, ret_ft);
		++failure;
	}
	else
	{
		printf("\n\033[32m[OK]\033[0m\n\n");
		++success;
	}
	printf("\033[36mEnd of width test, got %d success and %d failure, on 5 tests\033[0m\n\n\n", success, failure);
	return (success);
}

int	c_big_test(void)
{
	int ret_p;
	int ret_ft;
	int success;
	int failure;

	success = 0;
	failure = 0;
	printf("\033[31mBIG TEST :\033[0m %%-1c, '%%9c %%-9c %%c %%c %%c %%-c %%1c',  arg = 'c, \\0, *, \\0, (char)789, '*', C'\nTrue printf :\n");
	ret_p = printf("-<Ok so there|%9c|is that|%-9c| |%c| girl and |%c|... |%c| |%-c| |%c|>-", 'c', '\0', '*', '\0', (char)789, '*', 'C');
	printf(", return %d\nYour printf :\n", ret_p);
	ret_ft = ft_printf("-<Ok so there|%9c|is that|%-9c| |%c| girl and |%c|... |%c| |%-c| |%c|>-", 'c', '\0', '*', '\0', (char)789, '*', 'C');
	printf(", return %d\n", ret_ft);
	if (ret_p != ret_ft)
		printf("\n\033[31mToo bad, you failed the big test...\033[0m, expected %d\n got %d\n\n", ret_p, ret_ft);
	else
	{
		++success;
		printf("\n\n\033[32mCongratulation, you passed the big test!\033[0m\n\n");
	}
	return (success);
}
