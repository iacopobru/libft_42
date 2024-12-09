/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:22:00 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 11:22:13 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_isprint()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_isprint(i) == 0 && isprint(i) != 0){
			printf("[ERROR] ft_isprint return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, isprint(i), ft_isprint(i));
			printf("[EXIT TEST]\n");
			return (1);
		}
	}
	if (ft_isprint(EOF) == 0 && isprint(EOF) != 0){
		printf("[ERROR] ft_isprint return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}