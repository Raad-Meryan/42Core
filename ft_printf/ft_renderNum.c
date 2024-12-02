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

static void	handle_padding(t_data *data, int len, int content, char pad_char)
{
	int	padding;

	padding = len - content;
	if (padding > 0)
		putchar_buff_n(pad_char, padding, data);
}

unsigned long calc_abs_value(long num, int is_signed)
{
	if (is_signed && num < 0)
		return ((unsigned long)(-num));
	else
		return ((unsigned long)num);
}

int handle_precision(t_data *data, int num_len)
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

void handle_width_padding (t_data *data, int content_len)
{
	if (!data->flags.left_justified && data->flags.width > content_len)
		{
			if (data->flags.zero_pad == 1)
				handle_padding(data, data->flags.width, content_len, '0');
			else
				handle_padding(data, data->flags.width, content_len, ' ');
		}
}

void	print_num(t_data *data, long num, int is_signed)
{
	char			buffer[BUFFER_SIZE];
	int				content_len;
	int				prefix_len;
	int				num_len;
	int				zero_pad;
	char			*x;
	unsigned long	abs_num;

	prefix_len = add_prefix(data, num, buffer, !is_signed);
	x = prefix_len + buffer;
	abs_num = calc_abs_value(num, is_signed);
	base_convert(abs_num, data->flags.base, data->flags.uppercase, x);
	num_len = str_len(x);
	zero_pad = handle_precision(data, num_len);
	content_len = prefix_len + zero_pad + num_len;
	handle_width_padding(data, content_len);
	putstr_buff_n(buffer, prefix_len, data);
	putchar_buff_n('0', zero_pad, data);
	putstr_buff_n(x, num_len, data);
	if (data->flags.left_justified)
		handle_padding(data, data->flags.width, content_len, ' ');
}
