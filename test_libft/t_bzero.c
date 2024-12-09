/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bzero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:31:32 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 16:37:07 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_bzero()
{
	int		len;
	int		len_filler;
	char	*now_str;
	char	**test_str = gen_test_string();
	if (!test_str)
		return (1);
	char	**cp_test_str = copy_test_str(test_str);
	if (!cp_test_str)
		return (free_test_string(test_str), 0);
	for (int i = 0; i < NSTR; i++)
	{
		len = strlen(test_str[i]) + 1;
		len_filler = (rand() % len);
		now_str = strdup(test_str[i]);
		ft_bzero(test_str[i], len_filler);
		bzero(cp_test_str[i], len_filler);
		for (int j = 0; j < len; j++)
		{
			if (test_str[i][j] != cp_test_str[i][j])
			{
				printf("[ERROR] ft_bzero doesn't set the memory correctly\n");
				printf("string before bzero (n = %d):\n%s\n", len_filler,
					now_str);
				printf("At index %d, expected: %d, got: %d (%c)\n", j,
					cp_test_str[i][j], test_str[i][j], test_str[i][j]);
				printf("[EXIT THIS TEST]\n");
				free_test_string(cp_test_str);
				free_test_string(test_str);
				free(now_str);
				return (1);
			}
		}
		free(now_str);
	}
	free_test_string(cp_test_str);
	free_test_string(test_str);
	return (0);
}
