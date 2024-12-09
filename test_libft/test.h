/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:18:34 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/08 23:37:53 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../libft.h"
# include <stdbool.h>
# include <time.h>

# define NSTR 5000
# define LSTR_MAX 200

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

void	perform_test(void);

#endif