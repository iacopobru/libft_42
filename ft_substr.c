/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:19:32 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/12 16:48:00 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_sub;
	char	*dest;

	len_sub = ft_strlen(s) - start;
	if (len_sub > len)
		len_sub = len;
	dest = (char *)malloc(sizeof(char) * len_sub + 1);
	if (!dest)
		return (NULL);
	dest[len_sub] = '\0';
	while (len_sub--)
		dest[len_sub] = s[len_sub + start];
	return (dest);
}

// int main()
// {
// 	printf("(%s)\n", ft_substr("lorem ipsum dolor sit amet", 0, 1000));
// }