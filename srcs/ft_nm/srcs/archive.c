/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:09:30 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/23 16:09:32 by cpieri           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_nm.h"

static void		print_filename(char *name, char *file)
{
	write(1, "\n", 1);
	write(1, name, ft_strlen(name));
	write(1, "(", 1);
	write(1, file, ft_strlen(file));
	write(1, "):\n", 3);
}

int				parse_archive(t_file file)
{
	t_ar_header		*h;
	char			*str;
	size_t			len;

	h = (t_ar_header*)(file.ptr + SARMAG);
	file.ptr += ft_atol(h->ar_size) + sizeof(t_ar_header) + SARMAG;
	while (file.ptr)
	{
		h = (t_ar_header*)file.ptr;
		if (ft_atoi(h->ar_size) <= 0)
			return (0);
		print_filename(file.name, h->ar_fmag + 2);
		str = file.ptr + sizeof(t_ar_header);
		len = ft_strlen(str);
		while (!str[len++])
			;
		ft_nm((t_file){(void*)(str + len - 1), NULL, ft_atol(h->ar_size)});
		file.ptr += ft_atol(h->ar_size) + sizeof(t_ar_header);
	}
	return (0);
}
