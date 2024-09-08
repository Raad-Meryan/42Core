/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:14:22 by rmeryan           #+#    #+#             */
/*   Updated: 2024/09/08 08:14:27 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *s, int c, size_t n)
{
	size_t	x;
	unsigned char	*p;

	x = 0;
	p = (unsigned char *)s;
	while (x < n)
	{
		p[x] = c;
		x++;
	}
	return s;
}
