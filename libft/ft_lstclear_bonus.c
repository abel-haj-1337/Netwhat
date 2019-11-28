/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 06:50:13 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/18 18:27:37 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *l;

	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			tmp = l;
			l = l->next;
			del(tmp->content);
			free(tmp);
		}
		*lst = NULL;
	}
}

void		ft_d(void *data)
{
	if (data)
		data = NULL;
}

int			main(void)
{
	t_list *l1;
	t_list *l2;
	t_list *l3;
	t_list *l4;

	l1 = ft_lstnew("lorem");
	l2 = ft_lstnew("ipsum");
	l3 = ft_lstnew("sit");
	l4 = ft_lstnew("amet");
	ft_lstadd_back(&l1, l2);
	ft_lstadd_back(&l1, l3);
	ft_lstadd_back(&l1, l4);
	ft_lstprint(l1);
	ft_lstclear(&l2, &ft_d);
	ft_lstprint(l1);
	return (0);
}
