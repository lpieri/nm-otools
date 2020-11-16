#include "../includes/ft_nm.h"

static void 	parse_symtab_64(struct symtab_command* seg, s_file file)
{
	void			*strtab;
	void 			*symtab;
	struct nlist_64	*symbol_data;
	char 			*symname;
	uint32_t		nsyms;
	uint32_t		i;

	strtab = file.ptr + seg->stroff;
	symtab = file.ptr + seg->symoff;
	nsyms = seg->nsyms;
	i = 0;
	while (i < nsyms) {
		symbol_data = (struct nlist_64 *)symtab + i;
		symname = strtab + symbol_data->n_un.n_strx;
		if (symbol_data->n_value != 0 && ft_strcmp(symname, "\0") != 0)
		{
			ft_putstr(ft_hex64_to_char(swap_uint64t(symbol_data->n_value)));
			ft_putchar(' ');
		}
		else
			ft_putstr("                 ");
		print_symbol(symbol_data);
		if (ft_strcmp(symname, "\0") != 0)
			ft_putendl(symname);
		i++;
	}
}

void	parse_macho_64(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((struct mach_header_64*)file.ptr)->ncmds;
	lc = (struct load_command*)(file.ptr + sizeof(struct mach_header_64));
	while (ncmds--)
	{
		if (lc->cmd == LC_SYMTAB)
			parse_symtab_64((struct symtab_command*) lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}


static void 	parse_symtab(struct symtab_command* seg, s_file file)
{
	void			*strtab;
	void 			*symtab;
	struct nlist	*symbol_data;
	char 			*symname;
	uint32_t		nsyms;
	uint32_t		i;

	strtab = file.ptr + seg->stroff;
	symtab = file.ptr + seg->symoff;
	nsyms = seg->nsyms;
	i = 0;
	while (i < nsyms)
	{
		symbol_data = (struct nlist*)symtab + i;
		symname = strtab + symbol_data->n_un.n_strx;
		ft_putendl(symname);
		i++;
	}
}

void	parse_macho(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((struct mach_header*)file.ptr)->ncmds;
	lc = (struct load_command*)(file.ptr + sizeof(struct mach_header));
	while (ncmds--)
	{
		if (lc->cmd == LC_SYMTAB)
			parse_symtab((struct symtab_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}
