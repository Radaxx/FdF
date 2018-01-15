/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:58:45 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/11 14:43:11 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*tmp_src;
	char		*tmp_dst;
	char		tmp[len];
	size_t		i;

	i = 0;
	tmp_src = (char *)src;
	tmp_dst = (char *)dst;
	if (len > 100000000)
		return (0);
	while (i < len)
	{
		tmp[i] = tmp_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmp_dst[i] = tmp[i];
		i++;
	}
	return (tmp_dst);
}
