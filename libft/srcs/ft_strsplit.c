/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:02:27 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/15 15:34:13 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	cnt_wrd(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (!i && *s != c)
		{
			i = 1;
			++word;
		}
		else if (*s == c)
			i = 0;
		++s;
	}
	return (word);
}

static char		*wrd_cpy(char **s, char c)
{
	char	*tab;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while ((*s)[j] && (*s)[j] != c)
		++j;
	if (!(tab = ft_strnew(j)))
		return (NULL);
	while (**s && **s != c)
	{
		tab[i] = **s;
		++i;
		++(*s);
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab_split;
	char	*s1;
	size_t	i;
	size_t	w;

	if (!s)
		return (NULL);
	s1 = (char*)s;
	i = 0;
	w = cnt_wrd(s1, c);
	if (!(tab_split = ft_memalloc(sizeof(char*) * (w + 1))))
		return (NULL);
	while (i < w)
	{
		while (*s1 == c)
			++s1;
		tab_split[i] = wrd_cpy(&s1, c);
		++i;
	}
	tab_split[i] = 0;
	return (tab_split);
}
