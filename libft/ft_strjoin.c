/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:47:37 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 00:04:51 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = (char *)malloc(len_s1 + len_s2 + 1);
	if (new_string == NULL)
		return (NULL);
	while (i < len_s1 + len_s2)
	{
		if (i < len_s1)
			new_string[i] = s1[i];
		else
			new_string[i] = s2[i - len_s1];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
