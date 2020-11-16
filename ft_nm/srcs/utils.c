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

#include "../includes/ft_nm.h"

void	print_msg(const char *prog, const char *msg)
{
	ft_putstr_fd(prog, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(msg, 1);
}

void	print_error(const char *prog, const char *msg)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

s_file 	open_file(char *filename)
{
	int			fd;
	struct stat	stat;
	s_file		file;

	fd = 0;
	file.ptr = NULL;
	if ((fd = open(filename, O_RDONLY)) == FAILURE)
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

int 	check_macho_file(s_file file)
{
	uint32_t	magic;

	magic = ((uint32_t*)file.ptr)[0];
	if (magic == MH_MAGIC || magic == MH_MAGIC_64 || magic == MH_CIGAM ||
		magic == MH_CIGAM_64)
	{
		if (magic == MH_CIGAM_64 || magic == MH_MAGIC_64)
			return (1);
		else
			return (0);
	}
	return (FAILURE);
}