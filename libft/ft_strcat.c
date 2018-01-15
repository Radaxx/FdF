/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:17:41 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 10:17:29 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		len;
	char	*tmp_s2;

	i = 0;
	len = 0;
	tmp_s2 = (char *)s2;
	while (s1[len])
		len++;
	while (tmp_s2[i])
	{
		s1[i + len] = tmp_s2[i];
		i++;
	}
	s1[i + len] = '\0';
	return (s1);
}
