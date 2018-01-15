/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:40:17 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/08 18:41:33 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char	*tmp_s1;
	char	*tmp_s2;

	tmp_s1 = (char *)s1;
	tmp_s2 = (char *)s2;
	while ((*tmp_s1 && *tmp_s2) && *tmp_s1 == *tmp_s2)
	{
		tmp_s1++;
		tmp_s2++;
	}
	return ((unsigned char)*tmp_s1 - (unsigned char)*tmp_s2);
}
