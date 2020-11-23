/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:23:12 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 13:23:13 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_otool.h"

int 	print_msg(const char *prog, const char *msg, int ret)
{
	ft_putstr_fd(prog, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(msg, 1);
	return (ret);
}

int 	print_error(const char *prog, const char *msg)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	return (-1);
}

t_file 	open_file(char *filename)
{
	int			fd;
	struct stat	stat;
	t_file		file;

	file.ptr = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == FAILURE)
		return (file);
	if (fstat(fd, &stat) == -1 || S_ISDIR(stat.st_mode))
		return (file);
	file.len = stat.st_size;
	file.name = filename;
	file.ptr = mmap(NULL, stat.st_size, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd,
			  0);
	if (file.ptr == NULL)
		return (file);
	close(fd);
	return (file);
}
