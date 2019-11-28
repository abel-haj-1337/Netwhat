/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:10:22 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/04 23:55:44 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char unsigned	*string;

	i = 0;
	string = (unsigned char *)s;
	while (n > i)
	{
		if (string[i] == (unsigned char)c)
			return (void *)(string + i);
		i++;
	}
	return (NULL);
}
