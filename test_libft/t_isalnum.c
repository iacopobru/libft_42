/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isalnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:20:48 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 11:20:58 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_isalnum()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_isalnum(i) == 0 && isalnum(i) != 0){
			printf("[ERROR] ft_isalnum return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, isalnum(i), ft_isalnum(i));
			printf("[EXIT TEST]\n");
			return (1);
		}
	}
	if (ft_isalnum(EOF) == 0 && isalnum(EOF) != 0){
		printf("[ERROR] ft_isalnum return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}