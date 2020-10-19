//
// Created by Louise on 19/10/2020.
//

#include "little_libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
	write(fd, "\n", 1);
}

