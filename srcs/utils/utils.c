//
// Created by Louise on 19/10/2020.
//

#include "utils.h"
#include <stdio.h>

int     open_file(char *filename)
{
    int         fd;
    struct stat stat;

    fd = 0;
    if ((fd = open(filename, O_RDONLY)) == FAILURE)
        return (-1);
    if (fstat(fd, &stat) == -1)
        return (-1);
    printf("size of file: %lld\n", stat.st_size);
    return (fd);
}