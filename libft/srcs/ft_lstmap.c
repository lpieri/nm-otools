/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:21:22 by cpieri            #+#    #+#             */
/*   Updated: 2017/11/16 14:00:57 by cpieri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp1;
	t_list	*tmp2;

	if (!f || !lst)
		return (NULL);
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	tmp1 = new;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp2 = malloc(sizeof(t_list))))
			return (NULL);
		tmp2 = f(lst);
		tmp1->next = tmp2;
		tmp1 = tmp2;
		lst = lst->next;
	}
	return (new);
}
