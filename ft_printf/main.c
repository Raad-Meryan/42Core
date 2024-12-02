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
        ft_printf("This is a percent sign: [%%]\n"));  // Use '%%' to print '%'
    
    printf("\treal_CHARS=%d\n\n",
        printf("This is a percent sign: [%%]\n"));  // Same fix here
    
    printf("/////////////////////////\n");

    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a char with percent and dynamic width [%-*%]\n", n));  // Use '%%' to print '%'
    
    printf("\treal_CHARS=%d\n\n",
         printf("This is a char with percent and dynamic width [%%]\n"));
}

void test_str()
{
    char *s = "Raad Samer Meryan";

    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a str [%%s]: [%s]\n", s));

    printf("\treal_CHARS = %d\n\n",
        printf("This is a str [%%s]: [%s]\n", s));

    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a str [%%10s]: [%10s]\n", s));

    printf("\treal_CHARS = %d\n\n",
        printf("This is a str [%%10s]: [%10s]\n", s));

    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a str [%%10.3s]: [%10.3s]\n", s));

    printf("\treal_CHARS = %d\n\n",
        printf("This is a str [%%10.3s]: [%10.3s]\n", s));

    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a str [%%-10.3s]: [%-10.3s]\n", s));

    printf("\treal_CHARS = %d\n\n",
        printf("This is a str [%%-10.3s]: [%-10.3s]\n", s));

    printf("\tmine_CHARS = %d\n",
        ft_printf("This is a str [%%*.*s]: [%*.*s]\n", 3, 6, s));

    printf("\treal_CHARS = %d\n\n",
        printf("This is a str [%%*.*s]: [%*.*s]\n", 3, 6, s));

}


int main()
{   
    test_char();
    printf("\n/////\n");
    test_precent();
    printf("\n/////\n");
    test_str();
    return (0);
}

