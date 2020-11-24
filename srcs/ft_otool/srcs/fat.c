/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:09:37 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/23 16:09:38 by cpieri           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

static int	is_hostarch(cpu_type_t type)
{
	if (type == CPU_TYPE_X86_64 || type == CPU_TYPE_I386)
		return (1);
	return (0);
}

int			parse_fat(t_file file)
{
	uint32_t		nfat;
	t_fat_arch		*arch;
	t_file			new;
	uint32_t		i;

	nfat = swap_uint32t(((t_fat_header *)file.ptr)->nfat_arch);
	arch = (t_fat_arch*)(file.ptr + sizeof(t_fat_header));
	i = -1;
	while (++i < nfat)
	{
		new = (t_file){file.ptr + swap_uint32t(arch[i].offset), file.name,
			file.len};
		ft_otool(new);
		if (is_hostarch(swap_uint32t(arch[i].cputype)))
			return (0);
	}
	return (0);
}

int			parse_fat_64(t_file file)
{
	uint32_t		nfat;
	t_fat_arch_64	*arch;
	t_file			new;
	uint32_t		i;

	nfat = swap_uint32t(((t_fat_header *)file.ptr)->nfat_arch);
	arch = (t_fat_arch_64*)(file.ptr + sizeof(t_fat_header));
	i = -1;
	while (++i < nfat)
	{
		new = (t_file){file.ptr + swap_uint32t(arch[i].offset), file.name,
			file.len};
		ft_otool(new);
		if (is_hostarch(swap_uint32t(arch[i].cputype)))
			return (0);
	}
	return (0);
}
