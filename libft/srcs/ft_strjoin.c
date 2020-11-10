/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:53:18 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/14 09:21:46 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	k = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char*)malloc(sizeof(*s1) * (i + 1))))
		return (NULL);
	while (s1[j])
	{
		join[j] = s1[j];
		j++;
	}
	while (s2[k])
		join[j++] = s2[k++];
	join[j] = '\0';
	return (join);
}
