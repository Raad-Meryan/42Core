#include "ft_printf.h"

static int	add_prefix(t_data *data, long num, char *buffer, int unsignedNum)
{
	int	len;

	len = 0;
	if (num < 0 && !unsignedNum)
		buffer[len++] = '-';
	else if (data->flags.plus)
		buffer[len++] = '+';
	else if (data->flags.space)
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

void	print_num(t_data *data, long num, int is_signed)
{
	char	buffer[BUFFER_SIZE];
	int		content_len;
	int		prefix_len;
	char	*x;
	unsigned long	abs_num;

	prefix_len = add_prefix(data, num, buffer, !is_signed);
	x = prefix_len + buffer;
	if (is_signed && num < 0)
		abs_num = (unsigned long)(-num);
	else
		abs_num = (unsigned long)num;
	base_convert(abs_num, data->flags.base, data->flags.uppercase, x);
	content_len = str_len(buffer);
	if (!data->flags.left_justified)
	{
		if (data->flags.zero_pad == 1)
			handle_padding(data, data->flags.width, content_len, '0');
		else //if (data->flags.zero_pad == 0)
			handle_padding(data, data->flags.width, content_len, ' ');
	}
	putstr_buff_n(buffer, content_len, data);
	if (data->flags.left_justified)
		handle_padding(data, data->flags.width, content_len, ' ');
}
