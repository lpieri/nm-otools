/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:53:59 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/07 17:59:49 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(const void *s1, const void *s2, size_t len1, size_t len2)
{
	char	*join;
	char	*cpy1;
	char	*cpy2;
	size_t	i;
	size_t	j;

	cpy1 = (char*)s1;
	cpy2 = (char*)s2;
	if (!cpy1 || !cpy2)
		return (NULL);
	i = len1 + len2 + 1;
	if (!(join = (char*)ft_memalloc(sizeof(char) * i)))
	{
		ft_memdel((void**)&join);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (++i < len1)
		join[i] = cpy1[i];
	while (j < len2)
		join[i++] = cpy2[j++];
	return (join);
}
