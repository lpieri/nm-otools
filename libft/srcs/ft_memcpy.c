/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:22:31 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/16 14:17:51 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*srcs;

	dest = (char*)dst;
	srcs = (char*)src;
	i = 0;
	while (i != n)
	{
		dest[i] = srcs[i];
		i++;
	}
	return (dest);
}
