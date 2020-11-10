/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:17:10 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/13 16:26:01 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if ((mem = (char*)malloc(sizeof(*mem) * (size + 1))) == NULL)
		return (NULL);
	while (i <= size)
		mem[i++] = '\0';
	mem[i] = '\0';
	return (mem);
}
