/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:50:16 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 12:42:05 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp_dst;
	const char	*tmp_src;

	i = 0;
	tmp_src = src;
	tmp_dst = (char *)dst;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (tmp_dst);
}
