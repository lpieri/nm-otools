/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:22:59 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 13:23:03 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/ft_nm.h"
#include "little_libft.h"
#include "utils.h"

void 	print_symbol(void *file)
{
	write(1, file, 2000);
}

int		ft_nm(char *filename)
{
	void		*file;
	uint32_t	magic_nb;

	if ((file = open_file(filename)) == NULL)
	{
		print_error("ft_nm", "The opening of the file to fail");
		return (-1);
	}
	magic_nb = ((uint32_t*)file)[0];
	if (magic_nb != MAGIC_NUMBER) {
		print_error("ft_nm", "The file was not recognized as object file");
	} else {
		print_symbol(file);
	}
	return (0);
}
