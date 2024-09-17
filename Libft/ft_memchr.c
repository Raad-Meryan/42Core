
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *i;

    i = (unsigned char *)s;
    while (n--)
    {
        if(*i == (unsigned char)c)
            return ((void *)i);
        i++;
    }
    return (NULL);
}