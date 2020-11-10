/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:00:57 by cpieri            #+#    #+#             */
/*   Updated: 2018/01/13 14:17:04 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!s || (c < 0 || c > 127))
		return (NULL);
	tmp = (char*)s;
	if (c == '\0')
		return (tmp + ft_strlen(tmp));
	while (tmp[i])
	{
		if (tmp[i] == c)
		{
			tmp = tmp + i;
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
