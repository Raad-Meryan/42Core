#include "ft_printf.h"

static int init_data(t_data *data, const char *format)
{
    data->s = format;
    data->chars_written = 0;
    data->buffer = (char *)malloc(BUFFER_SIZE);
    if (!data->buffer)
        return (-1);
    data->buffer_index = 0;
    ft_memset(data->buffer, 0, BUFFER_SIZE * sizeof(char));
    return (0);
}
int ft_printf(const char *format, ...)
{
    t_data  data;

    va_start(data.args_pointer, format);
    if (init_data(&data, format))
        return (-1);
    while (*data.s)
    {
        // check if we have a format specifier
        if (*data.s == '%' && *(++data.s))
        {
            // parse the format specifier
            if (parse_format(&data))
                return (-1);
            render_format(&data);
        }
        else
        {
            // write the character to the buffer
            write_to_buff(&data, *data.s);
        }
        data.s++;
    }
    flush_bufff(&data);
    va_end(data.args_pointer);
    free(data.buffer);
    return (data.chars_written);
}