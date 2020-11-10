/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:57:10 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/22 15:37:23 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*c_dst;
	char	*c_src;

	i = 0;
	c_dst = (char*)dst;
	c_src = (char*)src;
	while (i < n)
	{
		if ((*c_dst++ = *c_src++) == (char)c)
			return (c_dst);
		i++;
	}
	return (NULL);
}
