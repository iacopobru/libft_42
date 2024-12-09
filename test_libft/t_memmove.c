/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:18:04 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 21:46:18 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	cp_test_memmove(void)
{
	int		len;
	char	*now_str;
	char	**t_str;
	char	**cp_t_str;

	t_str = gen_test_string();
	if (!t_str)
		return (1);
	cp_t_str = copy_test_str(t_str);
	if (!cp_t_str)
		return (free_test_string(t_str), 1);
	for (int i = 0; i < NSTR; i += 2)
	{
		now_str = strdup(t_str[i]);
		if (!(strlen(t_str[i]) && strlen(t_str[i + 1])))
			continue ;
		len = (strlen(t_str[i]) < strlen(t_str[i + 1])) ? rand()
			% strlen(t_str[i]) : rand() % strlen(t_str[i + 1]);
		if (ft_memmove(t_str[i], t_str[i + 1], len) != t_str[i])
		{
			printf("[ERROR] ft_memmove wrong return (addres/value\n");
			printf("[EXIT THIS TEST]\n");
			free_test_string(t_str);
			free_test_string(cp_t_str);
			return (free(now_str), 1);
		}
		memmove(cp_t_str[i], cp_t_str[i + 1], len);
		for (int j = 0; j < len; j++)
		{
			if (t_str[i][j] != cp_t_str[i][j])
			{
				printf("[ERROR] ft_memmove doesn't copy memory correct (size = \
					%d)\n", len);
				printf("string before ft_memmove: %s\nstring to copy: %s\n",
					now_str, t_str[i + 1]);
				printf("string expected: %s\nstring collected %s\n",
					cp_t_str[i], t_str[i]);
				printf("at index %d got %d (%c) expected %d (%c)\n", j,
					t_str[i][j], t_str[i][j], cp_t_str[i][j], cp_t_str[i][j]);
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

int	test_ft_memmove(void)
{
	int len;
	char *now_str;
	int rd[2];
	char **t_str = gen_test_string();
	if (!t_str || cp_test_memmove())
		return (1);
	char **cp_t_str = copy_test_str(t_str);
	if (!cp_t_str)
		return (free_test_string(t_str), 1);
	for (int i = 0; i < NSTR; i++)
	{
		now_str = strdup(t_str[i]);
		len = strlen(t_str[i]);
		rd[0] = (rand() % (len / 2 + 1));
		rd[1] = (rand() % (len / 2 + 1));
		if (ft_memmove(t_str[i] + rd[0], t_str[i] + rd[1], len / 2) != t_str[i]
			+ rd[0])
		{
			printf("[ERROR] ft_memmove wrong return addres/value\n");
			printf("[EXIT THIS TEST]\n");
			free_test_string(t_str);
			free_test_string(cp_t_str);
			return (free(now_str), 1);
		}
		memmove(cp_t_str[i] + rd[0], cp_t_str[i] + rd[1], len / 2);
		for (int j = 0; j < len / 2; j++)
		{
			if ((t_str[i] + rd[0])[j] != (cp_t_str[i] + rd[0])[j])
			{
				printf("[ERROR] ft_memmove doesn't copy memory correct in case of overlap (size = \
					%d)\n", len / 2);
				printf("string before ft_memmove: %s\nstring to copy: %s\n", \
					now_str + rd[0], now_str + rd[1]);
				printf("string expected: %s\nstring collected %s\n", cp_t_str[i] \
					+ rd[0], t_str[i] + rd[0]);
				printf("at index %d got %d (%c) expected %d (%c)\n", j, (t_str[i] \
						+ rd[0])[j], (t_str[i] + rd[0])[j], (cp_t_str[i] + rd[0])[j],
					(cp_t_str[i] + rd[0])[j]);
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
