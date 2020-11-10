/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:11:59 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/07 18:12:17 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbits(unsigned char octet)
{
	int		z;
	int		oct;

	oct = octet;
	z = 128;
	while (z > 0)
	{
		if (oct & z)
			ft_putchar('1');
		else
			ft_putchar('0');
		z >>= 1;
	}
}
