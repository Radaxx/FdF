/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:55:12 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 13:53:42 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	len2;
	char	*tmp_haystack;
	char	*tmp_needle;

	tmp_haystack = (char *)hay;
	tmp_needle = (char *)need;
	if (*tmp_needle == '\0')
		return (tmp_haystack);
	len2 = ft_strlen(tmp_needle);
	while (*tmp_haystack && len-- >= len2)
	{
		if (*tmp_haystack == *tmp_needle &&
				ft_memcmp(tmp_haystack, tmp_needle, len2) == 0)
			return (tmp_haystack);
		tmp_haystack++;
	}
	return (NULL);
}
