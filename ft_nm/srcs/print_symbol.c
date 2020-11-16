#include "../includes/ft_nm.h"

static char 	find_section(uint8_t sect, uint8_t type)
{
	char	ret;
//	ft_putnbr(sect);
	if (sect == 1)
		ret = 'T';
	else if (sect == 2)
		ret = 'D';
	else if (sect == 3)
		ret = 'B';
	else
		ret = 'S';
	if (!(type & N_EXT))
		ret -= 'A' - 'a';
	return (ret);
}

char 	print_symbol_64(s_nslist_64 *sym)
{
	if (sym->n_type & N_STAB)
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

char 	print_symbol(s_nslist *sym)
{
	if (sym->n_type & N_STAB)
		return ('-');
	else if ((N_TYPE & sym->n_type) == N_ABS)
		return ('A');
	else if ((N_TYPE & sym->n_type) == N_INDR)
		return ('I');
	return ('\0');
}