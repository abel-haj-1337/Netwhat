/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:17:11 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/18 18:40:31 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nhead;

	nhead = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			nlst = ft_lstnew(f(lst->content));
			if (!nlst)
			{
				ft_lstclear(&nhead, del);
				return (NULL);
			}
			ft_lstadd_back(&nhead, nlst);
			lst = lst->next;
		}
	}
	return (nhead);
}
