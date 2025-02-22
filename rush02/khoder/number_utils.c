#include "ft_rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
static void write_word(char *result, char *word, int need_hyphen)
{
    int len;

    len = ft_strlen(result);
    if (len > 0)
    {
        if (need_hyphen)
            result[len++] = '-';
        else
            result[len++] = ' ';
    }
    while (*word)
        result[len++] = *word++;
    result[len] = '\0';
}

static char *handle_tens(char **dict, char *num, char *result)
{
    char *tens;
    char *ones_str;
    char *word;

    tens = ft_strndup(num, 2);
    word = find_exact_match(dict, tens);
    if (word)
    {
        write_word(result, word, 0);
        free(word);
        free(tens);
        return (result);
    }
    free(tens);
    tens = malloc(3);
    if (!tens)
        return (result);
    tens[0] = num[0];
    tens[1] = '0';
    tens[2] = '\0';
    word = find_exact_match(dict, tens);
    if (word)
        write_word(result, word, 0);
    free(tens);
    free(word);
    if (num[1] != '0')
    {
        ones_str = malloc(2);
        if (!ones_str)
            return (result);
        ones_str[0] = num[1];
        ones_str[1] = '\0';
        word = find_exact_match(dict, ones_str);
        if (word)
            write_word(result, word, 1);  // Add hyphen for compound numbers
        free(ones_str);
        free(word);
    }
    return (result);
}

char *get_written_form(char **dict, char *number)
{
    char *result;
    char *word;
    int len;
    char group[4];
    char power[37];  // Big enough for very large numbers
    int i, j, group_len;

    if (!is_valid_number(number))
        return (NULL);
    result = malloc(sizeof(char) * MAX_NUM_LEN);
    if (!result)
        return (NULL);
    result[0] = '\0';
    len = ft_strlen(number);

    // Handle single digit and teens
    if (len == 1 || (len == 2 && number[0] == '1'))
    {
        word = find_exact_match(dict, number);
        if (word)
        {
            write_word(result, word, 0);
            free(word);
            return (result);
        }
    }
    // Handle two digits (20-99)
    else if (len == 2)
        return (handle_tens(dict, number, result));
    else
    {
        // Process number in groups of three from right to left
        i = len;
        while (i > 0)
        {
            // Get the current group (up to 3 digits)
            group_len = (i >= 3) ? 3 : i;
            j = 0;
            while (j < group_len)
            {
                group[j] = number[i - group_len + j];
                j++;
            }
            group[j] = '\0';
            i -= group_len;

            // Skip if group is all zeros
            if (ft_strcmp(group, "000") != 0)
            {
                // Handle hundreds
                if (group_len == 3 && group[0] != '0')
                {
                    group[1] = '\0';
                    word = find_exact_match(dict, group);
                    if (word)
                    {
                        write_word(result, word, 0);
                        free(word);
                        word = find_exact_match(dict, "100");
                        if (word)
                        {
                            write_word(result, word, 0);
                            free(word);
                        }
                    }
                    group[1] = number[i + 1];
                    group[2] = number[i + 2];
                    group[3] = '\0';
                }

                // Handle remaining digits in group
                if ((group_len == 3 && (group[1] != '0' || group[2] != '0')) || 
                    group_len < 3)
                {
                    if (group_len == 3)
                    {
                        // Handle last two digits
                        char last_two[3] = {group[1], group[2], '\0'};
                        word = get_written_form(dict, last_two);
                    }
                    else
                        word = get_written_form(dict, group);
                    
                    if (word)
                    {
                        write_word(result, word, 0);
                        free(word);
                    }
                }

                // Add power of 1000 if not the last group
                if (i > 0)
                {
                    power[0] = '1';
                    j = 1;
                    while (j <= i)
                    {
                        power[j] = '0';
                        j++;
                    }
                    power[j] = '\0';
                    word = find_exact_match(dict, power);
                    if (word)
                    {
                        write_word(result, word, 0);
                        free(word);
                    }
                }
            }
        }
        return (result);
    }
    free(result);
    return (NULL);
}
/*
static void	write_word(char *result, char *word)
{
	int	len;

	len = ft_strlen(result);
	if (len > 0 && result[len - 1] != ' ')
		result[len++] = ' ';
	while (*word)
		result[len++] = *word++;
	result[len] = '\0';
}

static char	*handle_tens(char **dict, char *num, char *result)
{
	char	*tens;
	char	*ones_str;
	char	*word;

	tens = ft_strndup(num, 2);
	word = find_exact_match(dict, tens);
	if (word)
	{
		write_word(result, word);
		free(word);
		free(tens);
		return (result);
	}
	free(tens);
	tens = malloc(3);
	if (!tens)
		return (result);
	tens[0] = num[0];
	tens[1] = '0';
	tens[2] = '\0';
	word = find_exact_match(dict, tens);
	if (word)
		write_word(result, word);
	free(tens);
	free(word);
	if (num[1] != '0')
	{
		ones_str = malloc(2);
		if (!ones_str)
			return (result);
		ones_str[0] = num[1];
		ones_str[1] = '\0';
		word = find_exact_match(dict, ones_str);
		if (word)
			write_word(result, word);
		free(ones_str);
		free(word);
	}
	return (result);
}
char *get_written_form(char **dict, char *number)
{
    char *result;
    char *word;
    int len;
    char *temp;
    int i;

    if (!is_valid_number(number))
        return (NULL);
    result = malloc(sizeof(char) * MAX_NUM_LEN);
    if (!result)
        return (NULL);
    result[0] = '\0';
    len = ft_strlen(number);

    // Handle single digit and teens
    if (len == 1 || (len == 2 && number[0] == '1'))
    {
        word = find_exact_match(dict, number);
        if (word)
        {
            write_word(result, word);
            free(word);
            return (result);
        }
    }
    // Handle two digits (20-99)
    else if (len == 2)
        return (handle_tens(dict, number, result));
    // Handle three digits (100-999)
    else if (len == 3)
    {
        // First digit for hundreds
        temp = malloc(2);
        if (!temp)
            return (NULL);
        temp[0] = number[0];
        temp[1] = '\0';
        
        word = find_exact_match(dict, temp);
        if (word)
        {
            write_word(result, word);
            free(word);
        }
        free(temp);
        
        // Add "hundred"
        word = find_exact_match(dict, "100");
        if (word)
        {
            write_word(result, word);
            free(word);
        }
        
        // Handle remaining two digits if not zero
        if (number[1] != '0' || number[2] != '0')
        {
            temp = malloc(3);
            if (!temp)
                return (NULL);
            temp[0] = number[1];
            temp[1] = number[2];
            temp[2] = '\0';
            
            word = get_written_form(dict, temp);
            if (word)
            {
                write_word(result, word);
                free(word);
            }
            free(temp);
        }
        return (result);
    }
    // Handle larger numbers (thousands and up)
    else
    {
        i = 0;
        while (len > 3)
        {
            if (number[i] != '0')
            {
                temp = ft_strndup(number + i, len > 3 ? len - 3 : len);
                word = get_written_form(dict, temp);
                if (word)
                {
                    write_word(result, word);
                    free(word);
                }
                free(temp);
                
                // Add thousand, million, etc.
                temp = malloc(len + 1);
                if (!temp)
                    return (NULL);
                temp[0] = '1';
                for (int j = 1; j <= len - 3; j++)
                    temp[j] = '0';
                temp[len - 3] = '\0';
                
                word = find_exact_match(dict, temp);
                if (word)
                {
                    write_word(result, word);
                    free(word);
                }
                free(temp);
            }
            len -= 3;
            i += 3;
        }
        
        // Handle remaining digits (less than 1000)
        if (len > 0)
        {
            temp = ft_strndup(number + i, len);
            word = get_written_form(dict, temp);
            if (word)
            {
                write_word(result, word);
                free(word);
            }
            free(temp);
        }
        return (result);
    }
    free(result);
    return (NULL);
}*/


/*
char	*get_written_form(char **dict, char *number)
{
	char	*result;
	char	*word;
	int		len;

	if (!is_valid_number(number))
		return (NULL);
	result = malloc(sizeof(char) * MAX_NUM_LEN);
	if (!result)
		return (NULL);
	result[0] = '\0';
	len = ft_strlen(number);
	if (len == 1 || (len == 2 && number[0] == '1'))
	{
		word = find_exact_match(dict, number);
		if (word)
		{
			write_word(result, word);
			free(word);
			return (result);
		}
	}
	else if (len == 2)
		return (handle_tens(dict, number, result));
	free(result);
	return (NULL);
}*/