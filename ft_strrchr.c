/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:49:19 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 01:10:53 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *last;

	last = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			last = str;
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return ((char *)last);
}