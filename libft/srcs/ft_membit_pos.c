/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_membit_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 14:07:35 by cpieri            #+#    #+#             */
/*   Updated: 2020/04/27 16:23:33 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putbits_pos(unsigned char octet)
{
	int		z;
	int		oct;

	oct = octet;
	z = 128;
	while (z > 0)
	{
		ft_putstr("|");
		if (oct & z)
			ft_putchar('1');
		else
			ft_putchar('0');
		z >>= 1;
	}
}

void	ft_membit_pos(void *s, size_t len, size_t size)
{
	size_t			i;
	size_t			y;
	unsigned char	*data;
	unsigned char	b;

	data = (unsigned char*)s;
	i = 0;
	ft_putstr("Position: ");
	while (i < 64)
	{
		ft_putstr("|");
		ft_putnbr((i + 1) % 8);
		if ((i + 1) % 8 == 0)
			ft_putstr("| - ");
		i++;
	}
	ft_putendl("");
	ft_putstr("Bits    : ");
	i = 0;
	while (i < (len * size))
	{
		y = 0;
		while (y < size)
		{
			b = data[i] >> ((size - y - 1) * 8);
			ft_putbits_pos(data[i++]);
			y++;
		}
		ft_putstr("| - ");
	}
	ft_putchar('\n');
}
