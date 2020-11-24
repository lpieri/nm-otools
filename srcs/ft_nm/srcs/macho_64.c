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

static char		get_symbol_64(t_nslist_64 *sym)
{
	char	letter;

	letter = '\0';
	if (N_STAB & sym->n_type)
		letter = '-';
	else if ((N_TYPE & sym->n_type) == N_UNDF)
	{
		if (sym->n_un.n_strx == 0)
			letter = 'C';
		if (sym->n_type & N_EXT)
			letter = 'U';
		else
			letter = '?';
	}
	else if ((N_TYPE & sym->n_type) == N_SECT)
		letter = find_section(sym->n_sect);
	else if ((N_TYPE & sym->n_type) == N_ABS)
		letter = 'A';
	else if ((N_TYPE & sym->n_type) == N_INDR)
		letter = 'I';
	return (!(sym->n_type & N_EXT) ? letter + 32 : letter);
}

static void		parse_symtab_64(t_symtab_command *seg, t_file file)
{
	void			*strtab;
	t_nslist_64		*symd;
	t_sym			*syms;
	uint32_t		nsyms;
	uint32_t		i;

	strtab = file.ptr + seg->stroff;
	nsyms = seg->nsyms;
	i = 0;
	syms = (t_sym*)mmap(NULL, nsyms * sizeof(t_sym), PROT_WRITE | PROT_READ,
			MAP_ANON | MAP_SHARED, 0, 0);
	while (i < nsyms)
	{
		symd = (t_nslist_64*)(file.ptr + seg->symoff) + i;
		syms[i].name = strtab + symd->n_un.n_strx;
		syms[i].print_value = 1;
		if (((symd->n_type & N_TYPE) == N_UNDF) && (symd->n_type & N_EXT))
			syms[i].print_value = 0;
		syms[i].value = symd->n_value;
		syms[i].symbol = get_symbol_64(symd);
		i++;
	}
	syms = sort_symbols(syms, nsyms);
	print_symbols(syms, nsyms);
	munmap(syms, nsyms * sizeof(t_sym));
}

static void		get_section_64(t_segment_command_64 *seg)
{
	t_section_64	*sec;
	uint32_t		nscets;

	sec = (t_section_64*)((void*)seg + sizeof(t_segment_command_64));
	nscets = seg->nsects;
	while (nscets--)
	{
		if (ft_strcmp(sec->sectname, SECT_TEXT) == 0 &&
			ft_strcmp(sec->segname, SEG_TEXT) == 0)
			var_index()->text = var_index()->index;
		if (ft_strcmp(sec->sectname, SECT_DATA) == 0 &&
			ft_strcmp(sec->segname, SEG_DATA) == 0)
			var_index()->data = var_index()->index;
		if (ft_strcmp(sec->sectname, SECT_BSS) == 0 &&
			ft_strcmp(sec->segname, SEG_DATA) == 0)
			var_index()->bss = var_index()->index;
		var_index()->index++;
		sec = (void*)sec + sizeof(t_section_64);
	}
}

int				parse_macho_64(t_file file)
{
	uint32_t		ncmds;
	t_load_command	*lc;

	ncmds = ((t_mach_header_64*)file.ptr)->ncmds;
	lc = (t_load_command*)(file.ptr + sizeof(t_mach_header_64));
	reset_index();
	while (ncmds--)
	{
		if (lc->cmd == LC_SEGMENT_64)
			get_section_64((t_segment_command_64*)lc);
		if (lc->cmd == LC_SYMTAB)
			parse_symtab_64((t_symtab_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
	return (0);
}
