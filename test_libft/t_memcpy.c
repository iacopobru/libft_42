/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:26:58 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 17:43:36 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_memcpy(void)
{
	int len;
	char *now_str;
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	char **cp_t_str = copy_test_str(t_str);
	if (!cp_t_str)
		return (free_test_string(t_str), 1);	
	for (int i = 0; i < NSTR; i += 2)
	{
		now_str = strdup(t_str[i]);
		if (!(strlen(t_str[i]) && strlen(t_str[i + 1])))
			continue;
		len = (strlen(t_str[i]) < strlen(t_str[i + 1])) ? rand() % strlen(t_str[i]) : rand() % strlen(t_str[i + 1]);
		if (ft_memcpy(t_str[i], t_str[i + 1], len) != t_str[i])
		{
			printf("[ERROR] ft_memcpy wrong return addres/value\n");
			printf("[EXIT THIS TEST]\n");
			free_test_string(t_str);
			free_test_string(cp_t_str);
			return (free(now_str), 1);
		}
		memcpy(cp_t_str[i], cp_t_str[i + 1], len);
		for (int j = 0; j < len; j++)
		{
			if (t_str[i][j] != cp_t_str[i][j])
			{
				printf("[ERROR] ft_memcpy doesn't copy memory correct (size = %d)\n", len);
				printf("string before ft_memcpy: %s\nstring to copy: %s\n", now_str, t_str[i + 1]);
				printf("string expected: %s\nstring collected %s\n", cp_t_str[i], t_str[i]);
				printf("at index %d got %d (%c) expected %d (%c)\n", j, t_str[i][j], t_str[i][j], cp_t_str[i][j], cp_t_str[i][j]);
				printf("[EXIT THIS TEST]\n");
				free_test_string(cp_t_str);
				free_test_string(t_str);
				return (free(now_str), 1);
			}
		}
		free(now_str);
	}
	free_test_string(cp_t_str);
	free_test_string(t_str);
	return (0);
}
