/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:53:46 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 11:28:53 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;
	size_t				i;

	i = 0;
	tmp_s1 = s1;
	tmp_s2 = s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && tmp_s1[i] == tmp_s2[i])
		i++;
	return (tmp_s1[i] - tmp_s2[i]);
}
