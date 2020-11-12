/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:41:27 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/12 12:41:30 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_hexdump(void *data, size_t size, uint64_t addr)
{
	size_t	i;

	i = 0;
	ft_putstr(ft_hex64_to_char(swap_uint64t(addr)));
	write(1, "\t", 1);
	while (i < size)
	{
		ft_puthexa(((unsigned char*)data)[i]);
		write(1, " ", 1);
		if ((i + 1) % 8 == 0 || i + 1 == size)
		{
			if ((i + 1) % 16 == 0 && i + 1 != size)
			{
				write(1, "\n", 1);
				addr += 16;
				ft_putstr(ft_hex64_to_char(swap_uint64t(addr)));
				ft_putchar('\t');
			}
			else if (i + 1 == size)
				write(1, "\n", 1);
		}
		i++;
	}
}
