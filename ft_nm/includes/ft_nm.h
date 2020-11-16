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

typedef struct	t_file
{
	void 		*ptr;
	char 		*name;
	size_t		len;
	int 		arch;
}				s_file;

void	parse_macho(s_file file);
void	parse_macho_64(s_file file);

int 	check_macho_file(s_file file);

s_file 	open_file(char *filename);
void	print_error(const char *prog, const char *msg);
void	print_msg(const char *prog, const char *msg);


#endif
