/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderNum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:22 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:40:23 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_prefix(t_data *data, long num, char *buffer, int unsignedNum)
{
	int	len;

	len = 0;
	if (num < 0 && !unsignedNum)
		buffer[len++] = '-';
	else if (data->flags.plus && !unsignedNum)
		buffer[len++] = '+';
	else if (data->flags.space && !unsignedNum)
		buffer[len++] = ' ';
	if (data->flags.hash && num != 0)
	{
		if (data->flags.specifier == 'x' || data->flags.specifier == 'p')
		{
			buffer[len++] = '0';
			buffer[len++] = 'x';
		}
		else if (data->flags.specifier == 'X')
		{
			buffer[len++] = '0';
			buffer[len++] = 'X';
		}
	}
	return (len);
}

static void	reverse_string(int i, char *buffer)
{
	int		j;
	int		k;
	char	temp;

	j = 0;
	k = i - 1;
	while (j < k)
	{
		temp = buffer[j];
		buffer[j] = buffer[k];
		buffer[k] = temp;
		j++;
		k--;
	}
}

void	base_convert(unsigned long num, int base, int uppercase, char *buffer)
{
	const char	*digits;
	int			i;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num)
		{
			buffer[i++] = digits[num % base];
			num /= base;
		}
	}
	buffer[i] = '\0';
	reverse_string(i, buffer);
}

void	print_num(t_data *data, long num, int is_signed)
{
	char	buffer[BUFFER_SIZE];
	int		prefix_len;

	prefix_len = add_prefix(data, num, buffer, !is_signed);
	base_convert(calc_abs_value(num, is_signed), data->flags.base,
		data->flags.uppercase, buffer + prefix_len);
	output_number(data, buffer, prefix_len);
}
