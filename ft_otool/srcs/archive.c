#include "../includes/ft_otool.h"

static void 	print_name(char *name)
{
	write(1, "Archive : ", 10);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

void	parse_archive(s_file file)
{
	s_ar_header		*header;

	print_name(file.name);
	file.ptr += SARMAG;
	header = (s_ar_header*)file.ptr;
	file.ptr += ft_atol(header->ar_size) + sizeof(s_ar_header);
	while (file.ptr)
	{
		header = (s_ar_header*)file.ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return ;
		write(1, header->ar_fmag + 2, 16);
		write(1, "\n", 1);
		ft_hexdump((void*)(file.ptr + + sizeof(s_ar_header)), ft_atoi
		(header->ar_size), (uint64_t)header);
		file.ptr +=  ft_atol(header->ar_size) + sizeof(s_ar_header);
	}
	return ;
}