#include "nm/ft_nm.h"

int		main(int ac, char **av) {
    int     i;

    if (ac >= 2)
    {
        i = 1;
        while (i < ac)
        {
            ft_nm(av[i]);
            i++;
        }
        return (0);
    }
	return (-1);
}
