/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:22:42 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 17:19:32 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	test_ft_strlen()
{
	char **test_str = gen_test_string();
	for (int i = 0; i < NSTR; i++)
	{
		if (ft_strlen(test_str[i]) != strlen(test_str[i]))
		{
			printf("[ERROR] ft_strlen return value incorrect\n");
			printf("string:\n%s\n", test_str[i]);
			printf("expected %ld, got %ld\n", strlen(test_str[i]),
				ft_strlen(test_str[i]));
			printf("[EXIT THIS TEST]\n");
			return (free_test_string(test_str), 1);
		}
	}
	const char msg[] = "hey how's going in 42?";
	ft_strlen(msg); // condition to check if the value is const char * or char *. compiler will complain if wrong.
	return (free_test_string(test_str), 0);
}