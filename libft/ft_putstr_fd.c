/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 02:24:42 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 00:03:24 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t			i;
	unsigned char	*string;

	if (s)
	{
		i = 0;
		string = (unsigned char *)s;
		while (string[i])
		{
			ft_putchar_fd(string[i], fd);
			i++;
		}
	}
}
