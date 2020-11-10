/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:50:09 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/16 14:32:48 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c_src;
	unsigned char	*c_dst;

	i = 0;
	c_src = (unsigned char*)src;
	c_dst = (unsigned char*)dst;
	if (c_src > c_dst)
	{
		while (i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			c_dst[len - 1] = c_src[len - 1];
			len--;
		}
	}
	return (dst);
}
