/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:18:08 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/10 11:15:31 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	run_test(int (*t_func)(), const char *t_name)
{
	if (!t_func())
		printf(C_YELLOW "[TEST]" "\e[1;37m" " %s " C_GREEN "OK\n" C_RESET, t_name);
}

void	perform_test(void)
{
	srand(time(NULL)); // imposto il seed per la generazione dei numeri casuali
	// srand(42);
	run_test(test_ft_isalpha, "ft_isalpha");
	run_test(test_ft_isdigit, "ft_isdigit");
	run_test(test_ft_isalnum, "ft_isalnum");
	run_test(test_ft_isascii, "ft_isascii");
	run_test(test_ft_isprint, "ft_isprint");
	run_test(test_ft_strlen, "ft_strlen");
	run_test(test_ft_memset, "ft_memset");
	run_test(test_ft_bzero, "ft_bzero");
	run_test(test_ft_memcpy, "ft_memcpy");
	run_test(test_ft_memmove, "ft_memmove");
	run_test(test_ft_strlcpy, "ft_strlcpy");
	run_test(test_ft_strlcat, "ft_strlcat");
	run_test(test_ft_toupper, "ft_toupper");
	run_test(test_ft_tolower, "ft_tolower");
	run_test(test_ft_strchr, "ft_strchr");
	run_test(test_ft_strrchr, "ft_strrchr");
	run_test(test_ft_strncmp, "ft_strncmp");
	run_test(test_ft_memchr, "ft_memchr");
}
