#include "ft_printf.h"

void test_char()
{
    printf(Y"\tmine_CHARS=%d"RST"\n");
     ft_printf("This is a char "Y"[%c]"RST"\n", 'A');
    printf("This is a char "G"[%c]"RST"\n", 'A');

    printf(Y"tmin_CHARS=%d"RST"\n");
    ft_printf("This is a char "Y"[%10c]"RST"\n", 'A');
    printf("This is a char "G"[%10c]"RST"\n", 'A');

    printf(Y"tmin_CHARS=%d"RST"\n");
    ft_printf("This is a char "Y"[%-10c]"RST"\n", 'A');
    printf("This is a char "G"[%-10c]"RST"\n", 'A');

    int n = 10;
    printf(Y"tmin_CHARS=%d"RST"\n", n);
    ft_printf("This is a char "Y"[%-*c]"RST"\n", n, 'A');
    printf("This is a char "G"[%-*c]"RST"\n", n, 'A');
}


int main()
{   
    test_char();
    return (0);
}

