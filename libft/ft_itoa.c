/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:26:11 by aparabos          #+#    #+#             */
/*   Updated: 2017/11/10 14:34:27 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		j;

	j = count_numbers(n);
	if (!(res = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	if (n == 0)
		return (ft_strcpy(res, "0"));
	i = j - 1;
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	res[j] = '\0';
	return (res);
}
