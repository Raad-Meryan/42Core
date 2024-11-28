#include "ft_printf.h"

void test_char()
{
    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a char "Y"[%c]"RST"\n", 'A'));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a char "G"[%c]"RST"\n", 'A'));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a char "Y"[%10c]"RST"\n", 'A'));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a char "G"[%10c]"RST"\n", 'A'));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a char "Y"[%-10c]"RST"\n", 'A'));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a char "G"[%-10c]"RST"\n", 'A'));

    printf("/////////////////////////\n");
    
    int n = 10;
    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a char "Y"[%-*c]"RST"\n", n, 'A'));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a char "G"[%-*c]"RST"\n", n, 'A'));

}

void test_precent()
{
    int n = 10;
    
    // Test without color formatting first
    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a char [%-*%]\n", n));  // Use '%%' to print '%'
    
    printf("\treal_CHARS=%d\n\n",
        printf("This is a char [%-*%%]\n", n));  // Same fix here
}



int main()
{   
    test_char();
    printf("\n/////\n");
    test_precent();
    return (0);
}

