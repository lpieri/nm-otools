/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:22:59 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 13:23:03 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm/ft_nm.h"
#include "little_libft.h"
#include "utils.h"

void	print_symbol(s_file file)
{
	size_t 	i;
	char *find;

	i = 0;
//	"__text__"
	if ((find = ft_strnstr(file.ptr, "__TEXT", file.len)) != NULL) {
		printf("%ld\n", find - (char*)file.ptr);
		int j = 0;
		while (j < find - (char*)file.ptr) {
			printf("%x = %c ", find[j], find[j]);
			j++;
		}
		void *test = file.ptr + (size_t)(find + 16);
		printf("%ld\n", file.ptr - test);
		j = 0;
		while (j < test - file.ptr) {
			printf("%c", ((char*)test)[j]);
			j++;
		}
	}
//	while (i < file.len) {
//		printf("%c", ((char*)file.ptr)[i]);
//		i++;
//	}
}

int		ft_nm(char *filename)
{
	s_file 		file;
	uint32_t	magic_nb;

	file = open_file(filename);
	if (file.ptr == NULL)
	{
		print_error("ft_nm", "The opening of the file to fail");
		return (-1);
	}
	magic_nb = ((uint32_t*)file.ptr)[0];
	if (magic_nb != MAGIC_NUMBER_64 && magic_nb != MAGIC_NUMBER_32)
	{
		print_error("ft_nm", "The file was not recognized as object file");
		return (-1);
	}
	print_symbol(file);
	return (0);
}
