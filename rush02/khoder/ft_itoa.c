#include <stdlib.h>

char *ft_itoa(int n)
{
    int len = 1;
    int tmp = n;
    char *str;

    // Handle negative numbers
    if (n < 0)
    {
        len++;
        tmp = -tmp;
    }

    // Calculate the length of the number
    while (tmp >= 10)
    {
        tmp /= 10;
        len++;
    }

    // Allocate memory for the string
    str = malloc(len + 1);
    if (!str)
        return NULL;

    str[len] = '\0';

    // Convert the number to a string
    if (n < 0)
        str[0] = '-';

    tmp = (n < 0) ? -n : n;

    while (--len >= 0 && str[len] != '-')
    {
        str[len] = (tmp % 10) + '0';
        tmp /= 10;
    }

    return str;
}
