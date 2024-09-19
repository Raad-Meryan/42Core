/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:14:51 by rmeryan           #+#    #+#             */
/*   Updated: 2024/09/19 08:14:54 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	i;

	if (!*little)
		return ((char *)big);
	i = 0;
	b = 0;
	while (big[i] && i < len)
	{
		l = 0;
		b = i;
		while (little[l] && big[b] && b < len)
		{
			if (little[l] != big[b])
				break ;
			l++;
			b++;
		}
		if (!little[l])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
