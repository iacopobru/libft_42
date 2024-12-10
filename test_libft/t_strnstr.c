/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:49:33 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 18:41:34 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char *t_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (*needle == '\0')
        return (char *)haystack;
    for (i = 0; i < len && haystack[i] != '\0'; i++)
    {
        for (j = 0; i + j < len && haystack[i + j] == needle[j]; j++)
        {
            if (needle[j + 1] == '\0')
                return (char *)(haystack + i);
        }
    }
    return NULL;
}

int test_ft_strnstr()
{
	char *little;
	char **t_str = gen_test_string();
	if (!t_str)
		return (1);
	for (int i = 0; i < NSTR; i++)
	{
		int rd = rand() % LSTR_MAX;
		little = (char *) malloc(sizeof(char) * rd + 1);
		int len = strlen(t_str[i]);
		int rd2 = 0;
		int index = 0;
		if (len != 0)
			rd2 = rand() % (len);
		while (index < rd && t_str[i][index + rd2] != '\0')
		{
			little[index] = t_str[i][index + rd2];
			index++;
		}
		little[rd] = '\0';
		rd = rand() % LSTR_MAX;
		char *res[2] = {t_strnstr(t_str[i], little, rd), ft_strnstr(t_str[i], little, rd)};
		if (res[0] != res[1])
		{
			printf(C_RED "[ERROR] " C_RESET "ft_strnstr wrong return address (len = %d)\n", rd);
			if (res[0] == NULL || res[1] == NULL)
				printf("expected %p, got %p\n", res[0], res[1]);
			else
				printf("expected %s got %s\n", res[0], res[1]);
			EXIT_TEST
			free(little);
			return (free_test_string(t_str), 1);
		}
		free(little);
	}
	return (free_test_string(t_str), 0);
}