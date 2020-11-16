#include "../includes/ft_nm.h"

static void 	parse_symtab_64(s_symtab_command* seg, s_file file)
{
	void			*strtab;
	void 			*symtab;
	s_nslist_64 	*symbol_data;
	char 			*symname;
	uint32_t		nsyms;
	uint32_t		i;

	strtab = file.ptr + seg->stroff;
	symtab = file.ptr + seg->symoff;
	nsyms = seg->nsyms;
	i = 0;
	while (i < nsyms) {
		symbol_data = (s_nslist_64*)symtab + i;
		symname = strtab + symbol_data->n_un.n_strx;
		if (symbol_data->n_value != 0 && ft_strcmp(symname, "\0") != 0)
		{
			ft_putstr(ft_hex64_to_char(swap_uint64t(symbol_data->n_value)));
			ft_putchar(' ');
		}
		else
			ft_putstr("                 ");
		ft_putchar(print_symbol_64(symbol_data));
		ft_putchar(' ');
		if (ft_strcmp(symname, "\0") != 0)
			ft_putendl(symname);
		i++;
	}
}

void	parse_macho_64(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((s_mach_header_64*)file.ptr)->ncmds;
	lc = (s_load_command*)(file.ptr + sizeof(s_mach_header_64));
	while (ncmds--)
	{
		if (lc->cmd == LC_SYMTAB)
			parse_symtab_64((s_symtab_command*) lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}


static void 	parse_symtab(s_symtab_command* seg, s_file file)
{
	void		*strtab;
	void 		*symtab;
	s_nslist 	*symbol_data;
	char 		*symname;
	uint32_t	nsyms;
	uint32_t	i;

	strtab = file.ptr + seg->stroff;
	symtab = file.ptr + seg->symoff;
	nsyms = seg->nsyms;
	i = 0;
	while (i < nsyms)
	{
		symbol_data = (s_nslist*)symtab + i;
		symname = strtab + symbol_data->n_un.n_strx;
		ft_putendl(symname);
		i++;
	}
}

void	parse_macho(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((s_mach_header*)file.ptr)->ncmds;
	lc = (s_load_command*)(file.ptr + sizeof(s_mach_header));
	while (ncmds--)
	{
		if (lc->cmd == LC_SYMTAB)
			parse_symtab((s_symtab_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}
