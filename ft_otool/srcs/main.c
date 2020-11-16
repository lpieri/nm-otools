#include "../includes/ft_otool.h"

static int 	ft_otool(char *filename)
{
	s_file 		file;

	file = open_file(filename);
	if (file.ptr == NULL)
	{
		print_error("ft_otool", "The opening of the file to fail");
		return (FAILURE);
	}
	if ((file.arch = check_macho_file(file)) == FAILURE)
	{
		print_msg(filename, "is not an object file");
		return (FAILURE);
	}
	if (file.arch == 1)
		parse_macho_64(file);
	else
		parse_macho(file);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;

	if (ac >= 2)
	{
		i = 1;
		while (i < ac)
		{
			ft_otool(av[i]);
			i++;
		}
		return (0);
	}
	return (FAILURE);
}