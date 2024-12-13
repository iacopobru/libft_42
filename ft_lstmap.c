/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrunial <ibrunial@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:52:00 by ibrunial          #+#    #+#             */
/*   Updated: 2024/12/13 14:10:33 by ibrunial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*my_list;
	t_list	*prev_node;
	t_list	*first_address;
	
	if (!lst)
		return (NULL);
	my_list = ft_lstnew(f(lst));
	lst = lst->next;
	prev_node = my_list;
	while (lst != NULL)
	{
		my_list = ft_lstnew(f(lst));
		lst = lst->next;
		prev_node->next = my_list;
	}
	return (first_address);
}
void *ff(void *st)
{
	char *s = st;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;	
	}
	return((void *)s);
}

int	main(void)
{
	t_list *elem;
	t_list *elem2;
	t_list *elem3;
	t_list *elem4;
	char *str = strdup("lorem");
	char *str2 = strdup("ipsum");
	char *str3 = strdup("dolor");
	char *str4 = strdup("sit");
	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem = ft_lstmap(elem, &ff, &free);
	while (elem != NULL)
	{
		printf("%s\n", (char *)elem->content);
		elem = elem->next;
	}
	write(1, "\100", 1);	
}