/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tolower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:13:50 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 00:14:21 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int test_ft_tolower()
{
	for (int i = 0; i <= UCHAR_MAX; i++){
		if (ft_tolower(i) != tolower(i)){
			printf("[ERROR] ft_tolower return value incorrect\n");
			printf("(value = %d (%c)) expected %d got %d\n",i, i, tolower(i), ft_tolower(i));
			printf("[EXIT TEST]\n");
			return (1);
		}
	}
	if (ft_tolower(EOF) != tolower(EOF)){
		printf("[ERROR] ft_tolower return value incorrect\n");
		printf("value EOF incorrect\n");
		printf("[EXIT THIS TEST]\n");
		return (1);	
	}
	return(0);
}