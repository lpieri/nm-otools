/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:57:09 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/13 17:08:46 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s1;

	if (!s)
		return (NULL);
	i = 0;
	s1 = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (s1 == NULL)
		return (NULL);
	while (s[i])
	{
		s1[i] = (*f)(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
