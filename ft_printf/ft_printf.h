/* the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.

I have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/
#ifndef ft_printf_h
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h> // For Variadic Stuff
#include <unistd.h> // For write
#include <stdlib.h> // For malloc, free

#define BUFFER_SIZE (1<<12) // 4096, the (1<<12) means 2^12, which is 4096

typedef unsigned char   byte;

#define FLAGS "-+ 0#"
#define NUMBERS "0123456789"
#define SPECIFIERS "cspdiuxX"

typedef enum
{
    BASE_2 = 2,
    BASE_8 = 8,
    BASE_10 = 10,
    BASE_16 = 16
}            e_base;

typedef struct s_flags
{
    int     left_justified; // 0 = right justified, 1 = left justified, why do we need it? Because we need to know if we need to add spaces to the right or left of the number
    int		minus;
    int		zero_pad; // 0 = no zero padding, 1 = zero padding
    int     space;
    int     hash; 
    
    char	specifier; // c, s, p, d, i, u, x, X, %, n
    
    int		width; // The width of the field
    int		precision; // The precision of the field

    int		uppercase;
    e_base	base; // The base of the number
}				t_flags; // This struct will hold all the flags that we need to keep track of

typedef struct s_data
{
    // pointer copy to format string
    const  char	*s; // I am doing this to pass this struct field with all the data to all the functions
    // va_list -> va_arg(args_pointer, type)
    va_list		args_pointer; // va_list to hold the arguments, and this to fetch the following variable
    // chars written
    int			chars_written; // This will hold the number of characters written
    // Buffer, 4k bools
    char		*buffer; // This will hold the buffer
    int			buffer_index; // This will hold the index of the buffer
    // All the bools that we need to keep track of [+-' '0#][width][.precision][specifier]
    t_flags     flags; 
}              t_data;

int ft_printf(const char *format, ...);
void ft_memset(void *s, byte c, size_t n);
int in(const char *s, char c);
int	ft_atoi(t_data *data);
int parse_format(t_data *data);

#endif