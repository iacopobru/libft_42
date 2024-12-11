/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:18:34 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/11 11:09:59 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../libft.h"
# include <stdbool.h>
# include <time.h>

# define NSTR 5000
# define LSTR_MAX 20
# define C_YELLOW "\e[1;33m"
# define C_GREEN "\e[0;32m"
# define C_RESET "\e[0m"
# define C_RED "\e[1;31m"
# define MALLOC_ERROR printf(C_RED "[MALLOC ERROR]\n" C_RESET);
# define EXIT_TEST printf(C_RED "[EXIT THIS TEST]\n" C_RESET);

char	**gen_test_string(void);
char	**copy_test_str(char **test_str);
void	free_test_string(char **str_arr);

int		test_ft_isalpha(void);
int		test_ft_isdigit(void);
int		test_ft_isalnum(void);
int		test_ft_isascii(void);
int		test_ft_isprint(void);
int		test_ft_strlen(void);
int		test_ft_memset(void);
int		test_ft_bzero(void);
int		test_ft_memcpy(void);
int		test_ft_memmove(void);
int		test_ft_strlcpy(void);
int		test_ft_strlcat(void);
int		test_ft_toupper(void);
int		test_ft_tolower(void);
int		test_ft_strchr(void);
int		test_ft_strrchr(void);
int		test_ft_strncmp(void);
int		test_ft_memchr(void);
int		test_ft_memcmp(void);
int		test_ft_strnstr(void);
int		test_ft_atoi(void);

void	perform_test(void);

#endif