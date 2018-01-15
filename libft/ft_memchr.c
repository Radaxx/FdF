/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:44:44 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 11:27:31 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			return ((char *)tmp + i);
		i++;
	}
	return (NULL);
}
