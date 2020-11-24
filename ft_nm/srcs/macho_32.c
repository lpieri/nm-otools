#include "../includes/ft_nm.h"

static char 	print_symbol(t_nslist *sym)
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

static void 	parse_symtab(t_symtab_command* seg, t_file file)
{
	void		*strtab;
	void 		*symtab;
	t_nslist 	*symbol_data;
	char 		*symname;
	uint32_t	nsyms;
	uint32_t	i;

	strtab = file.ptr + seg->stroff;
	symtab = file.ptr + seg->symoff;
	nsyms = seg->nsyms;
	i = 0;
	while (i < nsyms)
	{
		symbol_data = (t_nslist*)symtab + i;
		symname = strtab + symbol_data->n_un.n_strx;
		ft_putendl(symname);
		i++;
	}
}

int 	parse_macho(t_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((t_mach_header*)file.ptr)->ncmds;
	lc = (t_load_command*)(file.ptr + sizeof(t_mach_header));
	while (ncmds--)
	{
		if (lc->cmd == LC_SYMTAB)
			parse_symtab((t_symtab_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}