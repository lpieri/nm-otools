#include "../includes/ft_otool.h"

static void 	parse_segment_64(t_segment_command_64* seg, t_file file)
{
	struct section_64		*section;
	uint32_t				nscets;

	section = (struct section_64*)((void*)seg + sizeof(struct
		segment_command_64));
	nscets = seg->nsects;
	while (nscets--)
	{
		if (ft_strncmp(section->sectname, "__text", 16) == 0){
			ft_putstr(file.name);
			ft_putendl(":");
			ft_putstr("Contents of (__TEXT,__text) section\n");
			ft_hexdump((void*)(file.ptr + section->offset), section->size,
					   section->addr);
		}
		section = (void*)section + sizeof(struct section_64);
	}
}

int 			parse_macho_64(t_file file)
{
	uint32_t		ncmds;
	t_load_command	*lc;

	ncmds = ((t_mach_header_64*)file.ptr)->ncmds;
	lc = (t_load_command*)(file.ptr + sizeof(t_mach_header_64));
	while (ncmds--)
	{
		if (lc->cmd == LC_SEGMENT_64)
			parse_segment_64((t_segment_command_64*) lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
	return (0);
}

static void 	parse_segment(t_segment_command* seg, t_file file)
{
	struct section		*section;
	uint32_t			nscets;

	section = (struct section*)((void*)seg + sizeof(struct segment_command));
	nscets = seg->nsects;
	while (nscets--)
	{
		if (ft_strncmp(section->sectname, "__text", 16) == 0){
			ft_putstr(file.name);
			ft_putendl(":");
			ft_putstr("Contents of (__TEXT,__text) section\n");
			ft_hexdump((void*)(file.ptr + section->offset), section->size,
					   section->addr);
		}
		section = (void*)section + sizeof(struct section);
	}
}

int 			parse_macho(t_file file)
{
	uint32_t		ncmds;
	t_load_command	*lc;

	ncmds = ((t_mach_header*)file.ptr)->ncmds;
	lc = (t_load_command*)(file.ptr + sizeof(t_mach_header));
	while (ncmds--)
	{
		if (lc->cmd == LC_SEGMENT)
			parse_segment((t_segment_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
	return (0);
}
