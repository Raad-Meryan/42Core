#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char	*dest_ptr;
    unsigned char	*src_ptr;

    dest_ptr = (unsigned char *)dest;
    src_ptr = (unsigned char *)src;
    if (!dest || !src)
        return (NULL);
    while (n--)
        *dest_ptr++ = *src_ptr++;
    return (dest);
}