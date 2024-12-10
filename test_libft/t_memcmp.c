/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:27:05 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 15:30:53 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static size_t	t_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

int test_ft_memcmp()
{
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	for (int  i = 0; i < NSTR; i += 2)
	{
		int rd[2] = {rand() % LSTR_MAX, rand() % LSTR_MAX};
		t_strlcpy(t_str[i], t_str[i + 1], rd[0]);
		if (memcmp(t_str[i], t_str[i + 1], rd[1]) != ft_memcmp(t_str[i], t_str[i + 1], rd[1]))
		{
			printf(C_RED "[ERROR] " C_RESET "ft_memcmp wrong return value (n = %d)\n", rd[1]);
			printf("string tested s1: %s\n", t_str[i]);
			printf("string testet s2: %s\n", t_str[i + 1]);
			printf("expected %d, got %d\n", memcmp(t_str[i], t_str[i + 1], rd[1]), ft_memcmp(t_str[i], t_str[i + 1], rd[1]));
			EXIT_TEST
			return (free_test_string(t_str), 1);
		}	
	}
	return (free_test_string(t_str), 0);
}