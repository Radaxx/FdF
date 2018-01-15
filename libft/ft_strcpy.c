/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:03:31 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 14:31:52 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int			i;
	const char	*tmp_src;

	i = 0;
	tmp_src = src;
	while (tmp_src[i])
	{
		dst[i] = tmp_src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
