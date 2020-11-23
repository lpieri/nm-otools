#include "../includes/ft_otool.h"

static int 	ft_otool(char *filename)
{
	s_file 		file;
	uint32_t	magic;

	file = open_file(filename);
	if (file.ptr == NULL)
		return (print_error("ft_otool", "The opening of the file to fail"));
	magic = ((uint32_t*)file.ptr)[0];
	if (magic == MH_MAGIC || magic == MH_CIGAM)
		parse_macho(file);
	else if (magic == MH_CIGAM_64 || magic == MH_MAGIC_64)
		parse_macho_64(file);
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		parse_fat(file);
	else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
		parse_fat_64(file);
	else if (magic == AR_MAGIC || magic == AR_CIGAM)
		parse_archive(file);
	else
		return (print_msg(filename, "is not an object file", -1));
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