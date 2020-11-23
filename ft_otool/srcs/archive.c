/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:09:30 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/23 16:09:32 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

static void 	print_name(char *name)
{
	write(1, "Archive : ", 10);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

int	parse_archive(t_file file)
{
	t_ar_header		*header;
	char			*str;
	size_t			len;
	t_file			new;

	print_name(file.name);
	file.ptr += SARMAG;
	while (file.ptr)
	{
		header = (t_ar_header*)file.ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return (0);
		str = file.ptr + sizeof(t_ar_header);
		len = ft_strlen(str);
		while (!str[len++])
			;
		new = (t_file){(void*)(str + len - 1), header->ar_fmag + 2,
			ft_atol(header->ar_size)};
		ft_otool(new);
		file.ptr += ft_atol(header->ar_size) + sizeof(t_ar_header);
	}
	return (0);
}
