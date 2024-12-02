#include "ft_printf.h"

void	print_char(t_data *data, int c)
{
	int	width;

	width = data->flags.width;
	if (width > 1)
	{
		if (data->flags.left_justified)
		{
			putchar_buff_n((char)c, 1, data);
			putchar_buff_n(' ', width - 1, data);
		}
		else
		{
			putchar_buff_n(' ', width - 1, data);
			putchar_buff_n((char)c, 1, data);
		}
	}
	else
		putchar_buff_n((char)c, 1, data);
}
