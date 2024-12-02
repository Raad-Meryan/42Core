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

void test_numbers()
{
    int num = -12345;
    unsigned int unum = 4294967295; // Max value for 32-bit unsigned integer

    // Signed integers (%d and %i)
    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a signed number [%d]\n", num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a signed number [%d]\n", num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a signed number with width [%10d]\n", num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a signed number with width [%10d]\n", num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a signed number with precision [%.10d]\n", num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a signed number with precision [%.10d]\n", num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a signed number left-justified [%-10d]\n", num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a signed number left-justified [%-10d]\n", num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a signed number with width and precision [%10.5d]\n", num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a signed number with width and precision [%10.5d]\n", num));

    // Unsigned integers (%u)
    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is an unsigned number [%u]\n", unum));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is an unsigned number [%u]\n", unum));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is an unsigned number with width [%10u]\n", unum));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is an unsigned number with width [%10u]\n", unum));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is an unsigned number with precision [%.10u]\n", unum));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is an unsigned number with precision [%.10u]\n", unum));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is an unsigned number left-justified [%-10u]\n", unum));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is an unsigned number left-justified [%-10u]\n", unum));

    // Hexadecimal (%x and %X)
    unsigned int hex_num = 0x2A3F; // Example hexadecimal number

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a hex number (lowercase) [%x]\n", hex_num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a hex number (lowercase) [%x]\n", hex_num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a hex number (uppercase) [%X]\n", hex_num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a hex number (uppercase) [%X]\n", hex_num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a hex number with # flag [%#x]\n", hex_num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a hex number with # flag [%#x]\n", hex_num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a hex number with width [%10x]\n", hex_num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a hex number with width [%10x]\n", hex_num));

    printf("/////////////////////////\n");

    printf(Y"\tmine_CHARS=%d"RST"\n",
        ft_printf("This is a hex number with precision [%.10x]\n", hex_num));
    printf(Y"\treal_CHARS=%d"RST"\n",
        printf("This is a hex number with precision [%.10x]\n", hex_num));
}


int main()
{   
    test_char();
    printf("\n/////\n");
    test_precent();
    printf("\n/////\n");
    test_str();
    printf("\n/////\n");
    test_numbers();
    return (0);
}

