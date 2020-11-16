#ifndef FT_NM_H
# define FT_NM_H

# include "../../libft/include/libft.h"
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# define FAILURE	-1

# define N_STAB		0xe0
# define N_PEXT		0x10
# define N_TYPE		0x0e
# define N_EXT 		0x01

# define N_UNDF		0x0
# define N_ABS		0x2
# define N_SECT		0xe
# define N_PBUD		0xc
# define N_INDR		0xa

typedef struct mach_header		s_mach_header;
typedef struct mach_header_64	s_mach_header_64;
typedef struct load_command		s_load_command;
typedef struct symtab_command	s_symtab_command;
typedef struct nlist			s_nslist;
typedef struct nlist_64			s_nslist_64;

typedef struct	t_file
{
	void 		*ptr;
	char 		*name;
	size_t		len;
	int 		arch;
}				s_file;

void	parse_macho(s_file file);
void	parse_macho_64(s_file file);

char	print_symbol(s_nslist *sym);
char 	print_symbol_64(s_nslist_64 *sym);

int 	check_macho_file(s_file file);

s_file 	open_file(char *filename);
void	print_error(const char *prog, const char *msg);
void	print_msg(const char *prog, const char *msg);


#endif
