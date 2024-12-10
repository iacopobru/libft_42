/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:21:40 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 00:46:57 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strchr()
{
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	for (int i = 0; i < NSTR; i++)
	{
		int rd = rand() % CHAR_MAX;
		if (ft_strchr(t_str[i], rd) != strchr(t_str[i], rd))
		{
			printf("[ERROR] ft_strchr wrong return value\n");
			printf("string (search c = %d (%c)): %s\n", rd, rd, t_str[i]);
			if (ft_strchr(t_str[i], rd) == NULL)
				printf("return value NULL but expected index %ld (%c))\n" \
				, strchr(t_str[i], rd) - t_str[i], *strchr(t_str[i], rd));
			else if (strchr(t_str[i], rd) != NULL)
				printf("return value converted to index %ld (%c) expected %ld (%c)\n" \
				, ft_strchr(t_str[i], rd) - t_str[i], *ft_strchr(t_str[i], rd) \
				, strchr(t_str[i], rd) - t_str[i], *strchr(t_str[i], rd));
			else 
				printf("return value not NULL but expected NULL\n");
			printf("[EXIT THIS TEST]\n");
			return (free_test_string(t_str), 1);
		}
	}
	return (free_test_string(t_str), 0);
}