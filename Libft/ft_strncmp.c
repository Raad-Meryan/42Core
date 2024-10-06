/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 07:57:32 by rmeryan           #+#    #+#             */
/*   Updated: 2024/09/19 07:57:34 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s1_ptr != *s2_ptr)
			return (*s1_ptr - *s2_ptr);
		if (*s1_ptr == '\0')
			break ;
		s1_ptr++;
		s2_ptr++;
		i++;
	}
	return (0);
}
