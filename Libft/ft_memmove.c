/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:56:05 by rmeryan           #+#    #+#             */
/*   Updated: 2024/09/08 09:56:07 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	x;

	if (src < dest)
	{
		x = n;
		while (x > 0)
		{
			x--;
			((char *)dest)[x] = ((char *)src)[x];
		}
	}
	else if (src > dest)
	{
		x = 0;
		while (x < n)
		{
			((char *)dest)[x] = ((char *)src)[x];
			x++;
		}
	}
	return (dest);
}
