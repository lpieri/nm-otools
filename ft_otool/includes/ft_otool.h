#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "../../libft/include/libft.h"
# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# define FAILURE	-1

typedef struct mach_header			s_mach_header;
typedef struct mach_header_64		s_mach_header_64;
typedef struct load_command			s_load_command;
typedef struct segment_command		s_segment_command;
typedef struct segment_command_64	s_segment_command_64;

typedef struct fat_header		s_fat_header;

typedef struct	t_file
{
	void 		*ptr;
	char 		*name;
	size_t		len;
	int 		arch;
}				s_file;

void	parse_macho(s_file file);
void	parse_macho_64(s_file file);
void	parse_fat(s_file file);
void	parse_fat_64(s_file file);

void 	parse_segment(s_segment_command *seg, s_file file);
void 	parse_segment_64(s_segment_command_64 *seg, s_file file);

int 	check_macho_file(s_file file);

s_file 	open_file(char *filename);
void	print_error(const char *prog, const char *msg);
void	print_msg(const char *prog, const char *msg);

#endif
