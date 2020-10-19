#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <sys/stat.h>

# define FAILURE			-1

int     open_file(char *filename);

#endif
