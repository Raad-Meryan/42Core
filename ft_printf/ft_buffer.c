#include "ft_printf.h"

void	write_buff(t_data *data, char c)
{
	if(data->buffer_index==BUFFER_SIZE)
	{
		flush_buff(data);
	}
	data->buffer[data->buffer_index++] = c;

}

void	flush_buff(t_data *data)
{
	data->chars_written += write(STDOUT_FILENO, data->buffer, data->buffer_index);
	ft_memset(data->buffer, 0, BUFFER_SIZE);
	data->buffer_index = 0;
}

void putchar_buff_n(char c, int precision, t_data *data)
{
	if(precision <= 0)
		return ;
	while (precision--)
		write_buff(data, c);
}