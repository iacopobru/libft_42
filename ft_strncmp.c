/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:09:10 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/11 17:32:43 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp( const char * s1, const char * s2, size_t n )
{
    while ( n && *s1 && ( *s1 == *s2 ) )
    {
        ++s1;
        ++s2;
        --n;
    }
    if ( n == 0 )
    {
        return 0;
    }
    else
    {
        return ( *(unsigned char *)s1 - *(unsigned char *)s2 );
    }
}

int main()
{
	char c[] = "\201";
	printf("%d\n", strncmp("\201", "A", 20));
	printf("%d\n", strncmp(c, "A", 20));
	printf("carattere: (%c) int_value (%hhd)\n", *"\201", *"\201");
	printf("%d\n", *"\201");
}