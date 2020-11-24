#include "../includes/ft_nm.h"

t_sym 	*sort_symbols(t_sym *syms, uint32_t nsyms)
{
	t_sym		tmp;
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < nsyms)
	{
		j = i + 1;
		while (j < nsyms)
		{
			if (ft_strcmp(syms[i].name, syms[j].name) > 0 ||
				(ft_strcmp(syms[i].name, syms[j].name) == 0
					&& syms[i].value > syms[j].value))
			{
				tmp = syms[i];
				syms[i] = syms[j];
				syms[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (syms);
}

void	print_symbols(t_sym *syms, uint32_t nsyms)
{
	uint32_t	i;

	i = 0;
	while (i < nsyms)
	{
		if (syms[i].symbol != 'M' && syms[i].symbol != '-')
		{
			if (syms[i].value != 0 && ft_strcmp(syms[i].name, "\0") != 0)
				ft_putstr(ft_hex64_to_char(swap_uint64t(syms[i].value)));
			if (ft_strcmp(syms[i].name, "\0") != 0)
			{
				if (syms[i].value != 0)
					ft_putchar(' ');
				else
					ft_putstr("                 ");
				ft_putchar(syms[i].symbol);
				ft_putchar(' ');
				ft_putendl(syms[i].name);
			}
		}
		i++;
	}
}
