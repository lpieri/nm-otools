/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:05:10 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 14:05:12 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "../libft/include/libft.h"
# include <mach-o/loader.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

# define FAILURE			-1

typedef struct	t_file
{
	void 		*ptr;
	size_t		len;
}				s_file;

int		ft_nm(char *filename);

/*
**	Functions for Macho.
*/
int 	check_macho_file(s_file file);

s_file 	open_file(char *filename);
void	print_error(const char *prog, const char *msg);

#endif
