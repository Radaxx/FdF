/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:57:30 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 12:28:40 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*str;
	char	*tmp_s1;

	i = 0;
	len = 0;
	tmp_s1 = (char *)s1;
	while (tmp_s1[len])
		len++;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (tmp_s1[i])
	{
		str[i] = tmp_s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
