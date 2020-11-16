#include "../includes/ft_nm.h"

//static void 	parse_segment_64(struct segment_command_64* seg, s_file file)
//{
//	struct section_64		*section;
//	uint32_t				nscets;
//
//	section = (struct section_64*)((void*)seg + sizeof(struct
//		segment_command_64));
//	nscets = seg->nsects;
//	while (nscets--)
//	{
//		if (ft_strncmp(section->sectname, "__text", 16) == 0){
//			ft_putstr(file.name);
//			ft_putendl(":");
//			ft_putstr("Contents of (__TEXT,__text) section\n");
//			ft_hexdump((void*)(file.ptr + section->offset), section->size,
//					   section->addr);
//		}
//		section = (void*)section + sizeof(struct section_64);
//	}
//}
//
//void	parse_macho_64(s_file file)
//{
//	uint32_t				ncmds;
//	struct load_command*	lc;
//
//	ncmds = ((struct mach_header_64*)file.ptr)->ncmds;
//	lc = (struct load_command*)(file.ptr + sizeof(struct mach_header_64));
//	while (ncmds--)
//	{
//		if (lc->cmd == LC_SEGMENT_64)
//			parse_segment_64((struct segment_command_64*) lc, file);
//		lc = (void*)lc + lc->cmdsize;
//	}
//}


//static void 	parse_segment(struct segment_command* seg, s_file file)
//{
//	struct section		*section;
//	uint32_t			nscets;
//
//	section = (struct section*)((void*)seg + sizeof(struct segment_command));
//	nscets = seg->nsects;
//	while (nscets--)
//	{
//		if (ft_strncmp(section->sectname, "__text", 16) == 0){
//			ft_putstr(file.name);
//			ft_putendl(":");
//			ft_putstr("Contents of (__TEXT,__text) section\n");
//			ft_hexdump((void*)(file.ptr + section->offset), section->size,
//					   section->addr);
//		}
//		section = (void*)section + sizeof(struct section);
//	}
//}

void	parse_macho(s_file file)
{
	uint32_t				ncmds;
	struct load_command*	lc;

	ncmds = ((struct mach_header*)file.ptr)->ncmds;
	lc = (struct load_command*)(file.ptr + sizeof(struct mach_header));
	while (ncmds--)
	{
		if (lc->cmd == LC_SYMTAB)
//			parse_segment((struct segment_command*)lc, file);
		lc = (void*)lc + lc->cmdsize;
	}
}
