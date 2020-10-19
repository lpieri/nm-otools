/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:22:00 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 13:22:10 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/ft_nm.h"

int		main(int ac, char **av)
{
	int		i;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			ft_nm(av[i]);
			i++;
		}
		return (0);
	}
	return (-1);
}
