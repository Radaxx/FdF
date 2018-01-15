/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:38:41 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/09 11:51:34 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nb;
	int		neg;
	char	*tmp_str;

	i = 0;
	neg = 1;
	nb = 0;
	tmp_str = (char *)str;
	while ((tmp_str[i] >= '\t' && tmp_str[i] <= '\r') || tmp_str[i] == ' ')
		i++;
	if (tmp_str[i] == '-' && (tmp_str[i + 1] >= '0' && tmp_str[i + 1] <= '9'))
		neg = -1;
	if (tmp_str[i] == '-' || tmp_str[i] == '+')
		i++;
	while (tmp_str[i] >= '0' && tmp_str[i] <= '9')
	{
		nb = nb * 10 + (tmp_str[i] - 48);
		i++;
	}
	return (nb * neg);
}
