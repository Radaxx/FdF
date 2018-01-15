/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:48:58 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/11 17:03:15 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		if (!(new->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
	}
	if (new->content == NULL)
		new->content_size = 0;
	else
		new->content_size = content_size;
	new->next = NULL;
	return (new);
}
