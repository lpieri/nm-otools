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

#include "utils.h"
#include "little_libft.h"

void	print_error(const char *prog, const char *msg)
{
	ft_putstr_fd(prog, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
}

void	*open_file(char *filename)
{
	int			fd;
	void		*ptr;
	struct stat	stat;

	fd = 0;
	ptr = NULL;
	if ((fd = open(filename, O_RDONLY)) == FAILURE)
		return (NULL);
	if (fstat(fd, &stat) == -1 || S_ISDIR(stat.st_mode))
		return (NULL);
	ptr = mmap(NULL, stat.st_size, PROT_WRITE | PROT_READ, MAP_PRIVATE, fd, 0);
	if (ptr == NULL)
		return (NULL);
	close(fd);
	return (ptr);
}
