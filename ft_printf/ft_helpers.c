#include "ft_printf.h"

void	ft_memset(void *s, byte c, size_t n)
{
	byte	*ptr;

	ptr = (byte *)s;
	while (n)
	{
		*ptr++ = c;
		--n;
	}
}

int	in(const char *s, char c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_atoi(t_data *data)
{
	int	value;

	value = 0;
	while (in(NUMBERS, *data->s))
		value = value * 10 + (*data->s++ - '0');
	return (value);
}

int	str_len(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}