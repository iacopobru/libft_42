/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:21:19 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 11:21:28 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_isascii()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_isascii(i) == 0 && isascii(i) != 0){
			printf("[ERROR] ft_isascii return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, isascii(i), ft_isascii(i));
			printf("[EXIT TEST]\n");
			return (1);
		}
	}
	if (ft_isascii(EOF) == 0 && isascii(EOF) != 0){
		printf("[ERROR] ft_isascii return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}