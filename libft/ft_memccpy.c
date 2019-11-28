/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:42:33 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/04 23:55:11 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*f_string;
	unsigned char	*s_string;

	i = 0;
	f_string = (unsigned char *)dst;
	s_string = (unsigned char *)src;
	while (n > i)
	{
		f_string[i] = s_string[i];
		if (s_string[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
