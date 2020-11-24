#ifndef FT_NM_H
# define FT_NM_H

# include "../../libft/include/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/mman.h>

# include <stdio.h>

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/nlist.h>
# include <ar.h>

# define FAILURE	-1
# define AR_MAGIC 0x72613c21
# define AR_CIGAM 0x213c6172

# define N_STAB		0xe0
# define N_PEXT		0x10
# define N_TYPE		0x0e
# define N_EXT 		0x01

# define N_UNDF		0x0
# define N_ABS		0x2
# define N_SECT		0xe
# define N_PBUD		0xc
# define N_INDR		0xa

typedef struct mach_header			t_mach_header;
typedef struct mach_header_64		t_mach_header_64;
typedef struct fat_header			t_fat_header;
typedef struct ar_hdr				t_ar_header;

typedef struct fat_arch				t_fat_arch;
typedef struct fat_arch_64			t_fat_arch_64;

typedef struct load_command			t_load_command;
typedef struct segment_command		t_segment_command;
typedef struct segment_command_64	t_segment_command_64;
typedef struct section				t_section;
typedef struct section_64			t_section_64;
typedef struct symtab_command		t_symtab_command;
typedef struct nlist				t_nslist;
typedef struct nlist_64				t_nslist_64;

typedef struct	s_index
{
	size_t 		text;
	size_t		data;
	size_t		bss;
	size_t 		index;
}				t_index;

typedef struct	s_sym
{
	uint64_t	value;
	char 		symbol;
	char 		*name;
}				t_sym;

typedef struct	s_file
{
	void 		*ptr;
	char 		*name;
	size_t		len;
}				t_file;

int 	parse_macho(t_file file);
int 	parse_macho_64(t_file file);
int 	parse_fat(t_file file);
int 	parse_fat_64(t_file file);
int 	parse_archive(t_file file);

int 	ft_nm(t_file file);

void	print_symbols(t_sym *syms, uint32_t nsyms);

char 	find_section(uint8_t sect);
t_index    *var_index(void);
void        reset_index(void);

t_file 	open_file(char *filename);
int 	print_error(const char *prog, const char *msg);
int 	print_msg(const char *prog, const char *msg, int ret);

#endif
