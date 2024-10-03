#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    int     s1len;
    int     i;
    int     j;
    int     newsize;

    if (!s1 || !set)
        return (NULL);
    s1len = ft_strlen(s1);
    i = 0;
    while (i < s1len && ft_strchr(set, s1[i]) != NULL)
        i++;
    j = s1len - 1;
    while (j > i && ft_strchr(set, s1[j]) != NULL)
        j--;
    newsize = j - i + 1;
    str = (char *)malloc(newsize + 1);
    if (!str)
        return (NULL);
    j = 0;
    while (j < newsize)
        str[j++] = s1[i++];
    str[j] = '\0';
}