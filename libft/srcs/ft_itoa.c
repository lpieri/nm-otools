/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:39:14 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/16 09:58:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*itoa_cpy(int n, long nb, size_t len)
{
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
		s[0] = '-';
	s[len] = '\0';
	--len;
	while (nb > 9)
	{
		s[len] = nb % 10 + 48;
		nb = nb / 10;
		--len;
	}
	s[len] = nb % 10 + 48;
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	long	nb;
	long	tmp;
	size_t	len;

	nb = n;
	tmp = n;
	len = 0;
	if (n < 0)
		++len;
	if (nb < 0)
	{
		nb = nb * -1;
		tmp = nb;
	}
	while (tmp /= 10)
		++len;
	++len;
	s = itoa_cpy(n, nb, len);
	return (s);
}
