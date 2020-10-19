/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:02:34 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 14:03:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "little_libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}
