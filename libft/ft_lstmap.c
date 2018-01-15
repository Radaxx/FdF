/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:02:34 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 13:44:01 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!lst || !f)
		return (0);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = (*f)(lst);
	if (lst->next != NULL)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
