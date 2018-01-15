/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:37:48 by aparabos          #+#    #+#             */
/*   Updated: 2017/12/08 10:59:21 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoindel(char *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	tmp = ft_strcpy(tmp, s1);
	free(s1);
	tmp = ft_strcat(tmp, s2);
	return (tmp);
}
