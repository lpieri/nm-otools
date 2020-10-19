#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# define FAILURE			-1

void	print_error(const char *prog, const char *msg);
void    *open_file(char *filename);

#endif
