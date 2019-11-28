/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:55:23 by abel-haj          #+#    #+#             */
/*   Updated: 2019/11/05 00:02:07 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_split_incr(const char *s, size_t *i, char c, int equal_to)
{
	if (equal_to)
		while (s[*i] == c)
			*i += 1;
	else
		while (s[*i] && s[*i] != c)
			*i += 1;
}

static size_t	ft_countsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			j++;
	}
	return (j);
}

static size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char		**ft_freesplitted(char **s, size_t len)
{
	while (len + 1 > 0)
	{
		free(s[len]);
		len--;
	}
	free(s);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**result_array;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	k = ft_countsplit(s, c);
	result_array = (char **)malloc(sizeof(char *) * (k + 1));
	if (result_array == NULL)
		return (NULL);
	while (j < k)
	{
		ft_split_incr(s, &i, c, 1);
		result_array[j] = (char *)malloc(sizeof(char) * ft_strclen((s + i), c));
		if (!result_array[j])
			return (ft_freesplitted(result_array, j));
		result_array[j] = ft_substr(s, i, ft_strclen((s + i), c));
		ft_split_incr(s, &i, c, 0);
		j++;
	}
	result_array[j] = NULL;
	return (result_array);
}
