#include "../includes/ft_otool.h"

static void 	print_name(char *name)
{
	write(1, "Archive : ", 10);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

int 	parse_archive(s_file file)
{
	s_ar_header		*header;
	char			*str;
	size_t			len;
	s_file 			new;

	print_name(file.name);
	file.ptr += SARMAG;
	while (file.ptr)
	{
		header = (s_ar_header*)file.ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return (0);
		str = file.ptr + sizeof(s_ar_header);
		len = ft_strlen(str);
		while (!str[len++]);
		new = (s_file){(void*)(str + len - 1), header->ar_fmag + 2, ft_atol
		  (header->ar_size)};
		ft_otool(new);
		file.ptr +=  ft_atol(header->ar_size) + sizeof(s_ar_header);
	}
	return (0);
}