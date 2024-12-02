#include "ft_printf.h"

void	print_signed(t_data *data)
{
	int	num;

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
	char		buffer[BUFFER_SIZE];

	ptr = (unsigned long)va_arg(data->args_pointer, void *);
	putstr_buff_n("0x", 2, data);
	base_convert(ptr, BASE_16, 0, buffer);
	putstr_buff_n(buffer, str_len(buffer), data);
}
