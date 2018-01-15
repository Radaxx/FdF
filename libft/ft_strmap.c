/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:30:04 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 11:00:12 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	tmp = (char *)s;
	if (!(s))
		return (0);
	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(tmp[i]);
		i++;
	}
	return (res);
}
