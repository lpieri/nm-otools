/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex64_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:21:06 by cpieri            #+#    #+#             */
/*   Updated: 2020/01/06 09:14:27 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	conv_32hexa(char **s, long len_s, uint64_t hex)
{
	uint32_t	nb;
	long		i;
	char		tmp;

	nb = 0;
	i = 0;
	while (i < len_s)
	{
		nb = hex % 16;
		if (nb < 10)
			(*s)[i] = (nb) % 10 + '0';
		else
			(*s)[i] = (nb) + 'a' - 10;
		if ((i % 2) != 0)
		{
			tmp = (*s)[i];
			(*s)[i] = (*s)[i - 1];
			(*s)[i - 1] = tmp;
		}
		hex /= 16;
		i++;
	}
}

char		*ft_hex64_to_char(uint64_t hex)
{
	char	*s;

	if (!(s = (char*)ft_memalloc(sizeof(char) * (16 + 1))))
		return (NULL);
	if (hex < 16)
		s[0] = '0';
	conv_32hexa(&s, 16, hex);
	return (s);
}
