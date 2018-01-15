/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:58:39 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 10:12:05 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL || *alst == NULL)
		(*alst) = NULL;
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	free(*alst);
	(*alst) = NULL;
}
