/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:02:34 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 14:03:15 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] == haystack[i + j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char*)haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2 || !n)
		return (-1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
