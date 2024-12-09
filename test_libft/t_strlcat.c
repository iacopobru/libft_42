/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:40:29 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 23:28:30 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_strlcat()
{
	int		size;
	char	*now_str[2];
	char	**t_str;
	char	**cp_t_str;
	char dest1[LSTR_MAX * 2 + 1];
	char dest2[LSTR_MAX * 2 + 1];
	size_t	temp[2];

	t_str = gen_test_string();
	if (!t_str)
		return (1);
	cp_t_str = copy_test_str(t_str);
	if (!cp_t_str)
		return (free_test_string(t_str), 1);
	for (int i = 0; i < NSTR; i += 2)
	{
		now_str[0] = strdup(t_str[i]);
		now_str[1] = strdup(t_str[i + 1]);
		strcpy(dest1, t_str[i]);
		strcpy(dest2, t_str[i]);
		size = rand() % LSTR_MAX;
		temp[0] = ft_strlcat(dest2, cp_t_str[i + 1], size);
		temp[1] = strlcat(dest1, t_str[i + 1], size);
		if (temp[1] != temp[0])
		{
			printf("[ERROR] ft_strlcat wrong return value\n");
			printf("dest: %s\nsrc: %s\n", now_str[0], now_str[1]);
			printf("expected %zu got %zu\n", temp[1], temp[0]);
			printf("[EXIT THIS TEST]\n");
			free(now_str[0]); free(now_str[1]);
			free_test_string(t_str);
			free_test_string(cp_t_str);
			return (1);
		}
		for (int j = 0; j < size && dest1[j] != '\0'; j++)
		{
			if (dest1[j] != dest2[j])
			{
				printf("[ERROR] ft_strlcat doesn't concatenate properly\n");
				printf("dest: %s\nsrc: %s\n", now_str[0], now_str[1]);
				printf("expected: ");
				write(1, "", 0);
				write (1, dest1, size);
				printf("\ngot: ");
				write (1 , dest2, size);
				printf("\n[EXIT THIS TEST]\n");
				free(now_str[0]); free(now_str[1]);
				free_test_string(t_str);
				free_test_string(cp_t_str);
				return (1);
			}
		}
		free(now_str[0]); free(now_str[1]);
	}
	free_test_string(t_str);
	free_test_string(cp_t_str);
	return (0);
}
