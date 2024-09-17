/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:47:12 by rmeryan           #+#    #+#             */
/*   Updated: 2024/09/17 08:47:16 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	j = dstlen;
	if ((dstlen < size - 1) && size > 0)
	{
		while (src[i] && dstlen + i < size - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (dstlen >= size)
		dstlen = size;
	return (dstlen + srclen);
}
