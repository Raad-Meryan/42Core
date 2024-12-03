/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numUtils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeryan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:39:17 by rmeryan           #+#    #+#             */
/*   Updated: 2024/12/03 10:39:19 by rmeryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_padding(t_data *data, int len, int content, char pad_char)
{
	int	padding;

	padding = len - content;
	if (padding > 0)
		putchar_buff_n(pad_char, padding, data);
}

unsigned long	calc_abs_value(long num, int is_signed)
{
	if (is_signed && num < 0)
		return ((unsigned long)(-num));
	else
		return ((unsigned long)num);
}

int	handle_precision(t_data *data, int num_len)
{
	int	zero_pad;

	zero_pad = 0;
	if (data->flags.precision >= 0)
	{
		data->flags.zero_pad = 0;
		zero_pad = data->flags.precision - num_len;
		if (zero_pad < 0)
			zero_pad = 0;
	}
	return (zero_pad);
}

void	handle_width_padding(t_data *data, int content_len)
{
	if (!data->flags.left_justified && data->flags.width > content_len)
	{
		if (data->flags.zero_pad == 1)
			handle_padding(data, data->flags.width, content_len, '0');
		else
			handle_padding(data, data->flags.width, content_len, ' ');
	}
}

void	output_number(t_data *data, char *buffer, int prefix_len)
{
	int	num_len;
	int	zero_pad;
	int	content_len;

	num_len = str_len(buffer + prefix_len);
	zero_pad = handle_precision(data, num_len);
	content_len = prefix_len + zero_pad + num_len;
	handle_width_padding(data, content_len);
	putstr_buff_n(buffer, prefix_len, data);
	putchar_buff_n('0', zero_pad, data);
	putstr_buff_n(buffer + prefix_len, num_len, data);
	if (data->flags.left_justified)
		handle_padding(data, data->flags.width, content_len, ' ');
}
