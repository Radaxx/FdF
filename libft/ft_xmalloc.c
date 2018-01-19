/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:56:59 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/19 13:17:43 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_xmalloc(size_t size)
{
	void	*res;

	if (!(res = (void *)malloc(size)))
		ft_error("Error: Malloc failed.\n", EXIT_FAILURE);
	return (res);
}
