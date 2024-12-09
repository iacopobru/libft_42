/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:44:29 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 22:09:44 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strlcpy(void)
{
	char **t_str = gen_test_string();
	size_t rd;
	for (int i = 0; i < NSTR; i++)
	{
		rd = rand() % LSTR_MAX;
		char dest1[LSTR_MAX] = {0};
		char dest2[LSTR_MAX] = {0};
		if (strlcpy(dest1, t_str[i], rd) != ft_strlcpy(dest2, t_str[i], rd))
		{
			printf("[ERROR] ft_strlcpy return (value incorrect. expected %zu got \
				%zu\n", strlcpy(dest1, t_str[i], rd), ft_strlcpy(dest2, t_str[i],
					rd));
			printf("strig tested: %s\n", t_str[i]);
			printf("[EXIT THIS TEST]\n");
			return (free_test_string(t_str), 1);
		}
		for (size_t j = 0; j < LSTR_MAX; j++)
		{
			if (dest1[j] != dest2[j])
			{
				printf("[ERROR] ft_strlcpy doesn't copy correct (size = %zu) (len_str = %zu)\n", rd, strlen(t_str[i]));
				printf("strig tested: %s\n", t_str[i]);
				printf("at index %zu got %d (%c) expected %d (%c)\n", j, dest1[j], dest1[j], dest2[j], dest2[j]);
				printf("[EXIT THIS TEST]\n");
				return (free_test_string(t_str), 1);
			}
		}
	}
	return (free_test_string(t_str), 0);
}
