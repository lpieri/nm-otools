/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:28:20 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/10 12:33:24 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	sdst;
	size_t	ssrc;

	j = 0;
	sdst = ft_strlen(dst);
	ssrc = ft_strlen(src);
	if (size <= sdst)
		return (size + ssrc);
	i = sdst;
	while (src[j] && j < (size - sdst - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (sdst + ssrc);
}
