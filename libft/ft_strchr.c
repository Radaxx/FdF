/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:42:33 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/28 18:56:53 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (*tmp_s)
	{
		if (*tmp_s == c)
			return (tmp_s);
		tmp_s++;
	}
	if (*tmp_s == '\0' && c == '\0')
		return (tmp_s);
	return (NULL);
}
