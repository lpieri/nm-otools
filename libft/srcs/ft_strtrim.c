/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:08:53 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/16 14:51:32 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmer;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = (ft_strlen(s) - 1);
	j = 0;
	while (i >= 1 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j])
		j++;
	if (i < j)
		i = j;
	if (!(trimmer = ft_strsub(s, j, i - j + 1)))
		return (NULL);
	return (trimmer);
}
