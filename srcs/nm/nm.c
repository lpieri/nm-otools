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

#include "nm-otool.h"

void	print_symbol(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;
//	struct segment_command*	cmd;

	ncmds = ((struct mach_header_64*)file.ptr)->ncmds;
	lc = (struct load_command*)(file.ptr + sizeof(struct mach_header_64));
	printf("lc = %p, file.ptr = %p\n", lc, file.ptr);
	while (ncmds--)
	{
		printf("lc = %p, lc->cmd = %x\n", lc, lc->cmd);
		if (lc->cmd == LC_SEGMENT_64 || lc->cmd == LC_SEGMENT) {
			printf("lol\n");
		}
		lc = (void*)lc + lc->cmdsize;
	}
}

int		ft_nm(char *filename)
{
	s_file 		file;

	file = open_file(filename);
	if (file.ptr == NULL)
	{
		print_error("ft_nm", "The opening of the file to fail");
		return (FAILURE);
	}
	if (check_macho_file(file) != 0)
		return (FAILURE);
	print_symbol(file);
	return (0);
}
