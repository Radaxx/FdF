/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:08:50 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/13 18:46:13 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*tmp;

	i = 0;
	if (!(tmp = (char *)malloc(size + 1)))
		return (0);
	while (i <= size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
