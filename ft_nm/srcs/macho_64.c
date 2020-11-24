#include "../includes/ft_nm.h"

static char 	print_symbol_64(t_nslist_64 *sym)
{
	if (N_STAB & sym->n_type)
		return ('-');
	else if ((N_TYPE & sym->n_type) == N_UNDF)
	{
		if (sym->n_un.n_strx == 0)
			return ('C');
		if (sym->n_type & N_EXT)
			return ('U');
		else
			return ('?');
	}
	else if ((N_TYPE & sym->n_type) == N_SECT)
		return (find_section(sym->n_sect, sym->n_type));
	else if ((N_TYPE & sym->n_type) == N_ABS)
		return ('A');
	else if ((N_TYPE & sym->n_type) == N_INDR)
		return ('I');
	return ('\0');
}

static void 	parse_symtab_64(t_symtab_command *seg, t_file file)
{
	void			*strtab;
	void 			*symtab;
	t_nslist_64 	*symbol_data;
	char 			*symname;
	uint32_t		nsyms;
	uint32_t		i;

	strtab = file.ptr + seg->stroff;
	symtab = file.ptr + seg->symoff;
	nsyms = seg->nsyms;
	i = 0;
	// do malloc nsyms
	while (i < nsyms) {
		symbol_data = (t_nslist_64*)symtab + i;
		symname = strtab + symbol_data->n_un.n_strx;
		if (symbol_data->n_value != 0 && ft_strcmp(symname, "\0") != 0)
			ft_putstr(ft_hex64_to_char(swap_uint64t(symbol_data->n_value)));
		if (ft_strcmp(symname, "\0") != 0)
		{
			if (symbol_data->n_value != 0)
				ft_putchar(' ');
			else
				ft_putstr("                 ");
			ft_putchar(print_symbol_64(symbol_data));
			ft_putchar(' ');
			ft_putendl(symname);
		}
		i++;
	}
}

void 	get_section();

int 	parse_macho_64(t_file file)
{
	uint32_t		ncmds;
	t_load_command	*lc;

	ncmds = ((t_mach_header_64*)file.ptr)->ncmds;
	lc = (t_load_command*)(file.ptr + sizeof(t_mach_header_64));
	while (ncmds--)
	{
		if (lc->cmd == LC_SEGMENT_64)
			get_section();
		if (lc->cmd == LC_SYMTAB)
			parse_symtab_64((t_symtab_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
	return (0);
}
