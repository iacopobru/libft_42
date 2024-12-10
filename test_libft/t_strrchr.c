/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:21:40 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 00:55:28 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strrchr()
{
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	for (int i = 0; i < NSTR; i++)
	{
		int rd = rand() % CHAR_MAX;
		if (ft_strrchr(t_str[i], rd) != strrchr(t_str[i], rd))
		{
			printf("[ERROR] ft_strrchr wrong return value\n");
			printf("string (search c = %d (%c)): %s\n", rd, rd, t_str[i]);
			if (ft_strrchr(t_str[i], rd) == NULL)
				printf("return value NULL but expected index %ld (%c))\n" \
				, strrchr(t_str[i], rd) - t_str[i], *strrchr(t_str[i], rd));
			else if (strrchr(t_str[i], rd) != NULL)
				printf("return value converted to index %ld (%c) expected %ld (%c)\n" \
				, ft_strrchr(t_str[i], rd) - t_str[i], *ft_strrchr(t_str[i], rd) \
				, strrchr(t_str[i], rd) - t_str[i], *strrchr(t_str[i], rd));
			else 
				printf("return value not NULL but expected NULL\n");
			printf("[EXIT THIS TEST]\n");
			return (free_test_string(t_str), 1);
		}
	}
	return (free_test_string(t_str), 0);
}