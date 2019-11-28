/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:13:58 by abel-haj          #+#    #+#             */
/*   Updated: 2019/10/25 08:28:36 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ltrim;
	char	*rltrim;

	if (!s1 || !set)
		return (NULL);
	ltrim = ft_strlftrim(s1, set);
	if (!ltrim)
		return (NULL);
	rltrim = ft_strrgtrim(ltrim, set);
	return (rltrim);
}
