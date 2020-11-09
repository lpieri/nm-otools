/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:03:55 by cpieri            #+#    #+#             */
/*   Updated: 2020/10/19 14:04:02 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LITTLE_LIBFT_H
# define LITTLE_LIBFT_H

# include <unistd.h>

void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
