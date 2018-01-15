/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:17:10 by aparabos          #+#    #+#             */
/*   Updated: 2017/12/04 16:40:30 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	tmp = ft_strcpy(tmp, s1);
	tmp = ft_strcat(tmp, s2);
	return (tmp);
}
