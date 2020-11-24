/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:09:53 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/23 16:09:55 by cpieri           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

int			ft_otool(t_file file)
{
	uint32_t	magic;

	magic = ((uint32_t*)file.ptr)[0];
	if (magic == MH_MAGIC || magic == MH_CIGAM)
		return (parse_macho(file));
	else if (magic == MH_CIGAM_64 || magic == MH_MAGIC_64)
		return (parse_macho_64(file));
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		return (parse_fat(file));
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		return (parse_fat_64(file));
	else if (magic == AR_MAGIC || magic == AR_CIGAM)
		return (parse_archive(file));
	else
		return (print_msg(file.name, "is not an object file", -1));
}

static int	start(char *filename)
{
	t_file		file;

	file = open_file(filename);
	if (file.ptr == NULL)
		return (print_error("ft_otool", "The opening of the file to fail"));
	ft_otool(file);
	munmap(file.ptr, file.len);
	return (0);
}

int			main(int ac, char **av)
{
	int		i;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			start(av[i]);
			i++;
		}
		return (0);
	}
	return (FAILURE);
}
