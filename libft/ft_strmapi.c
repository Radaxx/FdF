/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:40:07 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 17:45:57 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	tmp = (char *)s;
	if (!(s))
		return (0);
	if (!(res = ft_strnew(ft_strlen(tmp))))
		return (0);
	while (s[i])
	{
		res[i] = (*f)(i, tmp[i]);
		i++;
	}
	return (res);
}
