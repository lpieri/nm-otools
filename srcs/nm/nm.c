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
#include "utils.h"

int		ft_nm(char *filename)
{
	void	*file;

	if ((file = open_file(filename)) == NULL)
	{
		print_error("ft_nm", "The opening of the file to fail");
		return (-1);
	}
	printf("%s\n", (char*)file);
	return (0);
}
