#include "ft_printf.h"

static void parse_flags(t_data *data)
{
    char    flag;
    while (in(FLAGS, *data->s))
    {
        flag = *data->s;
        if (flag == '-')
            data->flags.left_justified = 1;
        else if (flag == '0')
            data->flags.zero_pad = 1;
        else if (flag == '#')
            data->flags.hash = 1;
        else if (flag == ' ')
            data->flags.space = 1;
        else if (flag == '+')
            data->flags.minus = 1;
        data->s++;
    }
}

static int get_value(t_data *data, int *value)
{
    if (*data->s == '*')
    {
        *value = va_arg(data->args_pointer, int);
        ++data->s;
        return ;
    }
    *value = ft_atoi(data->s);
}

int parse_format(t_data *data)
{
    ft_memset(&data->flags, 0, sizeof(t_flags));
    data->flags.precision = -1;
    // parse flags
    parse_flags(data);
    // parse width
    get_value(data, &data->flags.width);
    // parse precision
    if (*data->s == '.' && *(++data->s))
        get_value(data, &data->flags.precision);
    if (!in(SPECIFIERS, *data->s))
        return (-1);
    else
    {
        data->flags.specifier = *data->s;
        if (in("diu", data->flags.specifier))
            data->flags.base = BASE_10;
        else if (in("xXp", data->flags.specifier))
        {
            data->flags.base = BASE_16;
            if ('X' == data->flags.specifier)
                data->flags.uppercase = 1;
        }
    }
    return (0);
}