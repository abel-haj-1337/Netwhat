/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:13:58 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 00:05:57 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrgtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	str_len;
	char	*new_string;

	if (!s1)
		return (NULL);
	str_len = ft_strlen(s1);
	while (str_len > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[str_len - 1] == set[j])
				break ;
			j++;
		}
		if (s1[str_len - 1] != set[j])
			break ;
		str_len--;
	}
	new_string = (char *)malloc(str_len + 1);
	if (new_string)
		ft_strlcpy(new_string, s1, str_len + 1);
	return (new_string);
}
