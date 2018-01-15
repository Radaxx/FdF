/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:40:54 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 10:47:40 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		start;
	int		i;
	int		len;
	char	*tmp;

	start = 0;
	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		start = i;
		while (s[i])
		{
			if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
				len = i - start;
			i++;
		}
		if ((tmp = ft_strnew(len)))
			return ((tmp = ft_strsub(s, start, len + 1)));
	}
	return (NULL);
}
