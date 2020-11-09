/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:04:09 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 14:04:56 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

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

void	print_error(const char *prog, const char *msg);
s_file 	open_file(char *filename);

#endif
