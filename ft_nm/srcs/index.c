#include "../includes/ft_nm.h"

t_index    *var_index(void)
{
	static t_index index = {0, 0, 0, 1};

	return (&index);
}

void        reset_index(void)
{
	var_index()->text = 0;
	var_index()->data = 0;
	var_index()->bss = 0;
	var_index()->index = 1;
}