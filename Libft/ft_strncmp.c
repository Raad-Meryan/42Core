#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    i = 0;
    while(i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    return (0); 
}
