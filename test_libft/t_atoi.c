/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:52:40 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/11 11:25:07 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char **gen_atoi_str()
{
	int L_str;
	char **str_arr = (char **)malloc(sizeof(char *) * NSTR);
	if (!str_arr)
	{
		printf(C_RED "[MALLOC ERROR] an allocation error occur in gen_aoi_string\n" C_RESET);
		return (NULL);
	}
	*str_arr = malloc(sizeof(char));
	**str_arr = '\0';
	str_arr[1] = strdup("2147483647");
	str_arr[2] = strdup("-2147483648");
	for (int i = 3; i < NSTR; i++){
		L_str = rand() % LSTR_MAX;
		if (L_str == 0)
			L_str = 1;
		str_arr[i] = (char *)malloc(sizeof(char) * L_str);
		bzero(str_arr[i], L_str);
		if (!str_arr[i])
		{
			printf(C_RED "[MALLOC ERROR] an allocation error occur in gen_atoi_string\n" C_RESET);
			while (i--)
				free(str_arr[i]);
			return (NULL);
		}
		for (int j = 0; j < L_str - 1; j++){
			if (rand() % 2 == 0)
				{str_arr[i][j] = "+-"[rand() % 2]; j++;}
			if (rand() % 2 == 0 && j < L_str - 1)
				{str_arr[i][j] = " \t\n\r\f\v"[rand() % 6]; j++;}
			if (rand() % 2 == 0 && j < L_str - 1)
				{str_arr[i][j] = "0123456789"[rand() % 10]; j++;}
			if (rand() % 5 == 0 && j < L_str - 1)
				{str_arr[i][j] = rand() % UCHAR_MAX; j++;}
			if (str_arr[i][j] == 0)
				j--;
		}
		str_arr[i][L_str - 1] = '\0';
	}
	return (str_arr);
}

static void print_readable(const char *s) {
    for (; *s; s++) {
        unsigned char c = (unsigned char)*s;
        if (isprint(c)) {
            putchar(c);
        } else {
            switch (c) {
                case '\n':
                    printf("\\n");
                    break;
                case '\t':
                    printf("\\t");
                    break;
                case '\r':
                    printf("\\r");
                    break;
                case '\f':
                    printf("\\f");
                    break;
                case '\v':
                    printf("\\v");
                    break;
                case '\a':
                    printf("\\a");
                    break;
                case '\b':
                    printf("\\b");
                    break;
                default:
                    printf("\\x%02X", c);
                    break;
            }
        }
    }
}

int test_ft_atoi()
{
	char **t_str = gen_atoi_str();
	for (int i = 0; i < NSTR; i++)
	{
		int res[2] = {atoi(t_str[i]), ft_atoi(t_str[i])};
		if (res[0] != res[1])
		{
			printf(C_RED "[ERROR] " C_RESET "wrong return value\n");
			printf("string tested:"); print_readable(t_str[i]);
			printf("\n[NOTE] not all part of the string could be printable\n");
			printf("expected %d got %d\n", res[0], res[1]);
			EXIT_TEST
			return(free_test_string(t_str), 1);
		}
	}
	free_test_string(t_str);
	return (0);
}