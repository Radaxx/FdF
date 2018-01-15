/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:28:35 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/15 15:42:06 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	size_t	res;
	int		i;

	i = 0;
	res = 1;
	if (s[0] == c)
		res = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			res++;
		i++;
	}
	return (res);
}

static char		**ft_loop(char const *s, char c, char **tmp)
{
	int		i;
	int		j;
	int		start;
	int		len;

	i = 0;
	j = 0;
	while (j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i;
		tmp[j] = ft_strsub(s, (unsigned int)start, (size_t)(len - start));
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tmp;

	if (!s)
		return (0);
	if (s[0] == '\0')
	{
		if (!(tmp = (char **)malloc(sizeof(char*))))
			return (NULL);
		tmp[0] = 0;
		return (tmp);
	}
	if (!(tmp = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1)))
		return (NULL);
	tmp = ft_loop(s, c, tmp);
	return (tmp);
}
