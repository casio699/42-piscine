#include "ft_rush02.h"
#include <stdlib.h>

char    *ft_strdup(char *str)
{
    int     len;
    char    *copy;

    len = ft_strlen(str);
    copy = malloc(sizeof(char) * (len + 1));
    if (!copy)
        return (NULL);
    for (int i = 0; i < len; i++)
        copy[i] = str[i];
    copy[len] = '\0';
    return (copy);
}
char *ft_strndup(const char *str, size_t n)
{
    size_t i;
    char *new_str;

    new_str = malloc(n + 1); // Allocate space for n characters + null terminator
    if (!new_str)
        return (NULL);

    for (i = 0; i < n && str[i] != '\0'; i++) {
        new_str[i] = str[i];
    }
    new_str[i] = '\0'; // Null terminate the string

    return (new_str);
}

int     ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strtrim(char *str)
{
    int start = 0;
    int end = ft_strlen(str) - 1;
    char *trimmed;

    while (str[start] == ' ' || str[start] == '\t')
        start++;
    while (str[end] == ' ' || str[end] == '\t')
        end--;
    if (start >= end)
        return (ft_strdup(""));
    trimmed = malloc(sizeof(char) * (end - start + 2));
    if (!trimmed)
        return (NULL);
    for (int i = start; i <= end; i++)
        trimmed[i - start] = str[i];
    trimmed[end - start + 1] = '\0';
    return (trimmed);
}

// Implement ft_split
char    **ft_split(char *str, char delimiter)
{
    int word_count = 0;
    int i = 0;
    int start = 0;
    char **result;

    // First pass: Count how many words are in the string
    while (str[i])
    {
        if (str[i] != delimiter && (i == 0 || str[i - 1] == delimiter))
            word_count++;
        i++;
    }

    result = malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);

    // Second pass: Split the string into words
    i = 0;
    int word_index = 0;
    while (str[i])
    {
        if (str[i] != delimiter)
        {
            start = i;
            while (str[i] && str[i] != delimiter)
                i++;
            result[word_index] = malloc(sizeof(char) * (i - start + 1));
            if (!result[word_index])
                return (NULL);
            for (int j = 0; j < (i - start); j++)
                result[word_index][j] = str[start + j];
            result[word_index][i - start] = '\0';
            word_index++;
        }
        else
            i++;
    }

    result[word_count] = NULL;
    return (result);
}

// Implement ft_strcmp
int     ft_strcmp(char *str1, char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return ((unsigned char)*str1 - (unsigned char)*str2);
}
