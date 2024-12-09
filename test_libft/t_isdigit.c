/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_isdigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:20:05 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 11:20:19 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_isdigit()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_isdigit(i) == 0 && isdigit(i) != 0){
			printf("[ERROR] ft_isdigit return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, isdigit(i), ft_isdigit(i));
			printf("[EXIT TEST]\n");
			return (1);
		}
	}
	if (ft_isdigit(EOF) == 0 && isdigit(EOF) != 0){
		printf("[ERROR] ft_isdigit return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}