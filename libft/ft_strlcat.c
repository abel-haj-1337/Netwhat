/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 15:10:42 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 17:40:28 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && src && !size)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len > size)
		return (src_len + size);
	ft_strlcpy((dst + dst_len), src, size - dst_len);
	return (dst_len + src_len);
}
