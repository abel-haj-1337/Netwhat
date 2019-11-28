/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:22:13 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/04 23:55:54 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f_string;
	unsigned char	*s_string;

	i = 0;
	f_string = (unsigned char*)s1;
	s_string = (unsigned char*)s2;
	while (n > i)
	{
		if (f_string[i] != s_string[i])
			return (f_string[i] - s_string[i]);
		i++;
	}
	return (0);
}
