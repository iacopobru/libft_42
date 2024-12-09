/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:18:08 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/09 14:40:43 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void perform_test()
{
	srand(time(NULL)); // imposto il seed per la generazione dei numeri casuali
	//srand(42);
	
	if(!test_ft_isalpha())
		printf("[TEST] ft_isalpha OK\n");
	if(!test_ft_isdigit())
		printf("[TEST] ft_isdigit OK\n");
	if(!test_ft_isalnum())
		printf("[TEST] ft_isalnum OK\n");
	if(!test_ft_isascii())
		printf("[TEST] ft_isascii OK\n");
	if(!test_ft_isprint())
		printf("[TEST] ft_isprint OK\n");
	if(!test_ft_strlen())
		printf("[TEST] ft_strlen OK\n");
	if(!test_ft_memset())
		printf("[TEST] ft_memset OK\n");
	if(!test_ft_bzero())
		printf("[TEST] ft_bzero OK\n");
	if(!test_ft_memcpy())
		printf("[TEST] ft_memcpy OK\n");
	if(!test_ft_memmove())
		printf("[TEST] ft_memmove OK\n");
	if(!test_ft_strlcpy())
		printf("[TEST] ft_strlcpy OK\n");
	if(!test_ft_strlcat())
		printf("[TEST] ft_strlcat OK\n");
}
