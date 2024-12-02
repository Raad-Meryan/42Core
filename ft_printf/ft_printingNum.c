#include "ft_printf.h"

void	print_signed(t_data *data)
{
	long	num;

	num = va_arg(data->args_pointer, int);
	print_num(data, num, 1);
}

void	print_unsigned(t_data *data)
{
	long	num;

	num = va_arg(data->args_pointer, unsigned int);
	print_num(data, num, 0);
}

void	print_hex(t_data *data, int uppercase)
{
	unsigned long	num;

	num = va_arg(data->args_pointer, unsigned int);
	data->flags.uppercase = uppercase;
	print_num(data, num, 0);
}

void	print_pointer(t_data *data)
{
	unsigned long	ptr;
	char			buffer[BUFFER_SIZE];
	int				num_len;
	int				content_len;
	const char		*nil_str = "(nil)";

	ptr = (unsigned long)va_arg(data->args_pointer, void *);
	if (ptr == 0)
	{
		num_len = str_len((char *)nil_str);
		content_len = num_len;
		if (!data->flags.left_justified && data->flags.width > content_len)
			handle_padding(data, data->flags.width, content_len, ' ');
		putstr_buff_n((char *)nil_str, num_len, data);
		if (data->flags.left_justified && data->flags.width > content_len)
			handle_padding(data, data->flags.width, content_len, ' ');
		return ;
	}
	base_convert(ptr, BASE_16, 0, buffer);
	num_len = str_len(buffer);
	content_len = 2 + num_len;
	if (!data->flags.left_justified && data->flags.width > content_len)
		handle_padding(data, data->flags.width, content_len, ' ');
	putstr_buff_n("0x", 2, data);
	putstr_buff_n(buffer, num_len, data);
	if (data->flags.left_justified && data->flags.width > content_len)
		handle_padding(data, data->flags.width, content_len, ' ');
}
