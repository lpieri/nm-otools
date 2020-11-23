#include "../includes/ft_otool.h"

int		parse_fat(s_file file)
{
	uint32_t 		nfat_arch;
	struct fat_arch_64	*arch;

	nfat_arch = ((s_fat_header *)file.ptr)->nfat_arch;
	arch = (struct fat_arch_64*)(file.ptr + sizeof(s_fat_header));
	while (nfat_arch--)
	{
		ft_hexdump((void*)(file.ptr + arch->offset), arch->size,
				   (uint64_t)(file.ptr + arch->offset));
		arch = (void*)arch + arch->size;
	}
	return (0);
}

int 	parse_fat_64(s_file file)
{
	uint32_t 		nfat_arch;
	s_load_command	*lc;

	nfat_arch = ((s_fat_header *)file.ptr)->nfat_arch;
	lc = (s_load_command*)(file.ptr + sizeof(s_fat_header));
	while (nfat_arch--)
	{
		if (lc->cmd == LC_SEGMENT)
			parse_segment_64((s_segment_command_64*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
	return (0);
}