/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:19:56 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 10:39:22 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char **gen_test_string()
{
	int L_str;
	char **str_arr = (char **)malloc(sizeof(char *) * NSTR);
	if (!str_arr)
	{
		printf(C_RED "[MALLOC ERROR] an allocation error occur in gen_test_string\n" C_RESET);
		return (NULL);
	}
	*str_arr = malloc(sizeof(char));
	**str_arr = '\0';
	for (int i = 0; i < NSTR; i++){
		L_str = rand() % LSTR_MAX;
		if (L_str == 0)
			L_str = 1;
		str_arr[i] = (char *)malloc(sizeof(char) * L_str);
		if (!str_arr[i])
		{
			printf(C_RED "[MALLOC ERROR] an allocation error occur in gen_test_string\n" C_RESET);
			while (i--)
				free(str_arr[i]);
			return (NULL);
		}
		for (int j = 0; j < L_str - 1; j++){
			str_arr[i][j] = "                  abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"[rand() % 81];
		}
		str_arr[i][L_str - 1] = '\0';
	}
	return (str_arr);
}

char	**copy_test_str(char **test_str)
{
	char	**cp_test_str;
	int		j;

	cp_test_str = (char **)malloc(sizeof(char *) * NSTR);
	if (!cp_test_str)
	{
		printf(C_RED "[MALLOC ERROR] an allocation error occur in copy_test_string\n" C_RESET);
		return (NULL);
	}
	for (int i = 0; i < NSTR; i++)
	{
		cp_test_str[i] = (char *)malloc(sizeof(char) * (strlen(test_str[i])
					+ 1));
		if (!cp_test_str[i])
		{
			printf(C_RED "[MALLOC ERROR] an allocation error occur in copy_test_string\n" C_RESET);
			while (i--)
				free(cp_test_str[i]);
			return (free(cp_test_str), NULL);
		}
		for (j = 0; test_str[i][j] != '\0'; j++)
			cp_test_str[i][j] = test_str[i][j];
		cp_test_str[i][j] = '\0';
	}
	return (cp_test_str);
}

void free_test_string(char **str_arr) {
    for (int i = 0; i < NSTR; i++) {
        free(str_arr[i]);
    }
    free(str_arr);
}