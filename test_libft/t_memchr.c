/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:01:36 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 11:25:31 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_memchr()
{
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	for (int i = 0; i < NSTR; i++)
	{
		int rd[2] = {rand() % UCHAR_MAX, rand() % (strlen(t_str[i]) + 1)};
		char *ris[2] = {ft_memchr(t_str[i], rd[0], rd[1]), memchr(t_str[i], rd[0], rd[1])};
		if (ris[0] != ris[1])
		{
			printf(C_RED "[ERROR]" C_RESET " ft_memchr wrong return value (c = %c), (n = %d)\n", rd[0], rd[1]);
			printf("tested string: %s\n", t_str[i]);
			if (ris[0] == NULL || ris[1] == NULL)
				printf("got %p but expected %p\n", ris[0], ris[1]);
			else
				printf("pointer converted to index got %ld (%c), expected %ld (%c)", ris[0] - t_str[i], *ris[0], ris[1] - t_str[i], *ris[1]);
			EXIT_TEST
			return (free_test_string(t_str), 1);
		}
	}
	return (free_test_string(t_str), 0);
}