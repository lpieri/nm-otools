/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:41:37 by cpieri            #+#    #+#             */
/*   Updated: 2019/03/20 12:41:16 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hexa(int nb)
{
	if (nb > 15)
		put_hexa(nb / 16);
	nb %= 16;
	if (nb < 10)
		ft_putnbr(nb);
	else
		ft_putchar(nb + 'a' - 10);
}

void		ft_puthexa(int nb)
{
	if (nb < 16)
		ft_putchar('0');
	put_hexa(nb);
}
