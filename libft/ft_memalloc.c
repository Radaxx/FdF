/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:57:51 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 19:33:50 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (char *)malloc(size)))
		return (NULL);
	if (!size)
		return (0);
	while (i < size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
