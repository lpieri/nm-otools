#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "../../libft/include/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/mman.h>

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <ar.h>

# include <stdio.h>

# define FAILURE	-1
# define AR_MAGIC 0x72613c21
# define AR_CIGAM 0x213c6172

typedef struct mach_header			s_mach_header;
typedef struct mach_header_64		s_mach_header_64;
typedef struct fat_header			s_fat_header;
typedef struct ar_hdr				s_ar_header;

typedef struct fat_arch				s_fat_arch;
typedef struct fat_arch_64			s_fat_arch_64;

typedef struct load_command			s_load_command;
typedef struct segment_command		s_segment_command;
typedef struct segment_command_64	s_segment_command_64;



typedef struct	t_file
{
	void 		*ptr;
	char 		*name;
	size_t		len;
}				s_file;

int 	ft_otool(s_file file);

int 	parse_macho(s_file file);
int 	parse_macho_64(s_file file);
int 	parse_fat(s_file file);
int 	parse_fat_64(s_file file);
int 	parse_archive(s_file file);

s_file 	open_file(char *filename);
int 	print_error(const char *prog, const char *msg);
int 	print_msg(const char *prog, const char *msg, int ret);

#endif
