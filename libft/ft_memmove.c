/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:40:53 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/03 20:38:48 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*f_string;
	unsigned char	*s_string;

	i = 0;
	f_string = (unsigned char *)dst;
	s_string = (unsigned char *)src;
	if (dst == src)
		return (dst);
	else if (dst > src)
		while (len > 0)
		{
			f_string[len - 1] = s_string[len - 1];
			len--;
		}
	else if (src != NULL)
		while (i < len)
		{
			f_string[i] = s_string[i];
			i++;
		}
	return (void *)(f_string);
}
