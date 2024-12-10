/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:43:33 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 10:36:56 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strncmp()
{
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	for (int  i = 0; i < NSTR; i += 2)
	{
		int rd[2] = {rand() % LSTR_MAX, rand() % LSTR_MAX};
		strlcpy(t_str[i], t_str[i + 1], rd[0]);
		if (strncmp(t_str[i], t_str[i + 1], rd[1]) != ft_strncmp(t_str[i], t_str[i + 1], rd[1]))
		{
			printf(C_RED "[ERROR] " C_RESET "ft_strncmp wrong return value (n = %d)\n", rd[1]);
			printf("string tested s1: %s\n", t_str[i]);
			printf("string testet s2: %s\n", t_str[i + 1]);
			printf("expected %d, got %d\n", strncmp(t_str[i], t_str[i + 1], rd[1]), ft_strncmp(t_str[i], t_str[i + 1], rd[1]));
			EXIT_TEST
			return (1);
		}	
	}
	return (free_test_string(t_str), 0);
}