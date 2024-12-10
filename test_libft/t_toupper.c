/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_toupper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:02:50 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 00:10:59 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_toupper()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_toupper(i) != toupper(i)){
			printf("[ERROR] ft_toupper return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, toupper(i), ft_toupper(i));
			printf("[EXIT TEST]\n");
			return (1);
		}
	}
	if (ft_toupper(EOF) != toupper(EOF)){
		printf("[ERROR] ft_toupper return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}