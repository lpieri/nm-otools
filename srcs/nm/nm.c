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

void 	parse_segment(struct segment_command_64* seg, s_file file)
{
	struct section_64		*section;
	uint32_t				nscets;

	section = (struct section_64*)((void*)seg + sizeof(struct
		segment_command_64));
	nscets = seg->nsects;
	while (nscets--)
	{
		if (ft_strncmp(section->sectname, "__text", 16) == 0){
			ft_putstr(file.name);
			ft_putendl(":");
			ft_putstr("Contents of (__TEXT,__text) section\n");
			ft_hexdump((void*)(file.ptr + section->offset), section->size,
			  section->addr);
		}
		section = (void*)section + sizeof(struct section_64);
	}
}

void	parse_macho(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((struct mach_header_64*)file.ptr)->ncmds;
	lc = (struct load_command*)(file.ptr + sizeof(struct mach_header_64));
	while (ncmds--)
	{
		if (lc->cmd == LC_SEGMENT_64 || lc->cmd == LC_SEGMENT)
			parse_segment((struct segment_command_64*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}

int		ft_nm(char *filename)
{
	s_file 		file;

	file = open_file(filename);
	if (file.ptr == NULL)
	{
		print_error("ft_otool", "The opening of the file to fail");
		return (FAILURE);
	}
	if (check_macho_file(file) != 0)
	{
		print_msg(filename, "is not an object file");
		return (FAILURE);
	}
	parse_macho(file);
	return (0);
}
