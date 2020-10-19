//
// Created by Louise on 19/10/2020.
//

#include "utils.h"
#include <stdio.h>
#include <sys/mman.h>

int     open_file(char *filename)
{
    int         fd;
    void        *ptr = NULL;
    struct stat stat;

    fd = 0;
    if ((fd = open(filename, O_RDONLY)) == FAILURE)
        return (-1);
    if (fstat(fd, &stat) == -1)
        return (-1);
    printf("size of file: %lld\n", stat.st_size);
    ptr = mmap(NULL, stat.st_size, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd, 0);
    printf("size of file: %p\n", ptr);
    return (fd);
}