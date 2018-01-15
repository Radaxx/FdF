/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:46:09 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/09 17:25:51 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		a;
	char	*tmp_s;

	i = 0;
	a = -1;
	tmp_s = (char *)s;
	while (tmp_s[i])
	{
		if (tmp_s[i] == c)
			a = i;
		i++;
	}
	if (tmp_s[i] == '\0' && c == '\0')
		a = i;
	if (a == -1)
		return (NULL);
	return (tmp_s + a);
}
