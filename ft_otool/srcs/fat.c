#include "../includes/ft_otool.h"

static int	is_hostarch(cpu_type_t type)
{
	if (type == CPU_TYPE_X86_64 || type == CPU_TYPE_I386)
		return (1);
	return (0);
}

int		parse_fat(s_file file)
{
	uint32_t 		nfat;
	s_fat_arch		*arch;
	s_file 			new;
	uint32_t 		i;

	nfat = swap_uint32t(((s_fat_header *)file.ptr)->nfat_arch);
	arch = (s_fat_arch*)(file.ptr + sizeof(s_fat_header));
	i = -1;
	while (++i < nfat)
	{
		new = (s_file){file.ptr + swap_uint32t(arch[i].offset), file.name,file.len};
		ft_otool(new);
		if (is_hostarch(swap_uint32t(arch[i].cputype)))
			return (0);
	}
	return (0);
}

int		parse_fat_64(s_file file)
{
	uint32_t 		nfat;
	s_fat_arch_64	*arch;
	s_file 			new;
	uint32_t 		i;

	nfat = swap_uint32t(((s_fat_header *)file.ptr)->nfat_arch);
	arch = (s_fat_arch_64*)(file.ptr + sizeof(s_fat_header));
	i = -1;
	while (++i < nfat)
	{
		new = (s_file){file.ptr + swap_uint32t(arch[i].offset), file.name,file.len};
		ft_otool(new);
		if (is_hostarch(swap_uint32t(arch[i].cputype)))
			return (0);
	}
	return (0);
}