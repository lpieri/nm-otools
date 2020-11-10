/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:00:57 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/10 12:43:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = (char*)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (tmp + ft_strlen(s));
	while (i >= 0)
	{
		if (tmp[i] == c)
		{
			tmp = tmp + i;
			return (tmp);
		}
		i--;
	}
	return (0);
}
