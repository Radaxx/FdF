/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:25:12 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 13:51:07 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*tmp_src;
	char	*tmp_dst;

	i = 0;
	tmp_src = (char *)src;
	tmp_dst = (char *)dst;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_dst[i] == c)
			return (tmp_dst + i + 1);
		i++;
	}
	return (NULL);
}
