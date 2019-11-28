/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:39:00 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/11 00:53:09 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*f_string;
	char	*s_string;

	i = 0;
	f_string = dst;
	s_string = (char *)src;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (s_string[i] && size - 1 > i)
	{
		f_string[i] = s_string[i];
		i++;
	}
	f_string[i] = '\0';
	return (ft_strlen(s_string));
}
