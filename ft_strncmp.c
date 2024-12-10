/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:09:10 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 10:43:40 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	
	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i >= n)
		return (0);
	return (s1[i] - s2[i]);
}
