/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_memset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:24:55 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 14:13:20 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_memset()
{
	char *dest1;
	char *dest2;
	int filler = rand();
	int size;
	for (int i = 0; i < 1000; i++)
	{
		size = rand() % 1000;
		dest1 = malloc(size);
		dest2 = malloc(size);
		if (!dest1 || !dest2)
		{
			printf("problema con l'allocazione di malloc in test_ft_memset\n");
			return (free(dest1), free(dest2), 1);
		}
		if (ft_memset(dest1, filler, size) != dest1)
		{
			printf("[ERROR] ft_memset doesn't return (the correct address\n");
			printf("[EXIT THIS TEST]");
			return (free(dest1), free(dest2), 1);
		}
		memset(dest2, filler, size);
		for (int j = 0; j < size; j++)
		{
			if (dest1[j] != dest2[j])
			{
				printf("[ERROR] ft_memset doesn't set the correct value\n");
				printf("expected %c got %c in the %d byte of %d\n", dest2[j],
					   dest1[j], j + 1, size);
				printf("[EXIT THIS TEST]\n");
				return (free(dest1), free(dest2), 1);
			}
		}
		free(dest1);
		free(dest2);
	}
	return (0);
}