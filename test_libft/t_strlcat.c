/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:40:29 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:07 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static size_t	t_strlcat(char *dest, const char *src, size_t size)
{
	size_t dest_len = 0;
	size_t src_len = 0;
	size_t i;

	while (dest[dest_len] != '\0' && dest_len < size)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if ((dest_len + i) < size)
		dest[dest_len + i] = '\0';

	return (dest_len + src_len);
}

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
		temp[1] = t_strlcat(dest1, t_str[i + 1], size);
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
