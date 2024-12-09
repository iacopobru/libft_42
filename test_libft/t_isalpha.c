/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isalpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:18:57 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 11:19:09 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_isalpha()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_isalpha(i) == 0 && isalpha(i) != 0){
			printf("[ERROR] ft_isalpha return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, isalpha(i), ft_isalpha(i));
			printf("[EXIT THIS TEST]\n");
			return (1);
		}
	}
	if (ft_isalpha(EOF) == 0 && isalpha(EOF) != 0){
		printf("[ERROR] ft_isalpha return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}