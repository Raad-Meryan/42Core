/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:47:48 by rmeryan           #+#    #+#             */
/*   Updated: 2024/09/17 09:47:49 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*start;

	start = (char *)s;
	str = start + ft_strlen(s);
	while (str != (start - 1))
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
