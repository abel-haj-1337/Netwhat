/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:01:50 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/04 23:59:30 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t result;

	result = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		result = -((size_t)n);
	}
	else
		result = n;
	if (result < 10)
		ft_putchar_fd(result + 48, fd);
	else
	{
		ft_putnbr_fd(result / 10, fd);
		ft_putchar_fd((result % 10) + 48, fd);
	}
}
