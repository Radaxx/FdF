/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:34:47 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/09 12:19:07 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_str(char *haystack, char *needle, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (needle[i] != haystack[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		len;
	char	*tmp_needle;
	char	*tmp_haystack;

	i = 0;
	len = 0;
	tmp_haystack = (char *)haystack;
	tmp_needle = (char *)needle;
	len = ft_strlen(tmp_needle);
	if (*tmp_needle == '\0')
		return (tmp_haystack);
	while (tmp_haystack[i])
	{
		if (test_str(tmp_haystack + i, tmp_needle, len) == 1)
			return (tmp_haystack + i);
		i++;
	}
	return (0);
}
