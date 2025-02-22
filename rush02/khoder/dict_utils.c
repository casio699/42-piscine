#include "ft_rush02.h"


void free_dictionary(char **dict)
{
    int i;

    if (!dict)
        return;
    i = 0;
    while (dict[i])
    {
        free(dict[i]);
        i++;
    }
    free(dict);
}

static int count_dict_entries(char **dict)
{
    int count;

    count = 0;
    if (!dict)
        return (0);
    while (dict[count])
        count++;
    return (count);
}

char *find_exact_match(char **dict, char *number)
{
    int i;
    int dict_size;

    if (!dict || !number)
        return (NULL);
    
    dict_size = count_dict_entries(dict);
    i = 0;
    while (i < dict_size - 1) // Make sure we don't access beyond array bounds
    {
        // For debugging
        //print_dict_entry(dict[i], dict[i + 1]);
        
        if (ft_strcmp(dict[i], number) == 0)
            return (ft_strdup(dict[i + 1]));
        i += 2;
    }
    return (NULL);
}

// Added this function to validate dictionary entries
int validate_dictionary(char **dict)
{
    int i;
    
    if (!dict)
        return (0);
    
    i = 0;
    while (dict[i] && dict[i + 1])
    {
        // Verify that the number entry is valid
        if (!is_valid_number(dict[i]))
            return (0);
        // Verify we have the essential numbers (0-9, 10-19, 20,30,...90, 100, 1000)
        i += 2;
    }
    return (1);
}
// char *find_exact_match(char **dict, char *number)
// {
//     int i;

//     if (!dict || !number)
//         return (NULL);
    
//     i = 0;
//     while (dict[i] && dict[i + 1]) // Dictionary entries are stored in pairs
//     {
//         if (ft_strcmp(dict[i], number) == 0)
//             return (ft_strdup(dict[i + 1]));
//         i += 2;
//     }
//     return (NULL);
// }
static int	parse_line(char *line, char **number, char **word)
{
	int		i;
	int		j;
	char	*temp_num;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		return (0);
	temp_num = malloc(sizeof(char) * (i + 1));
	if (!temp_num)
		return (0);
	j = 0;
	while (j < i)
	{
		temp_num[j] = line[j];
		j++;
	}
	temp_num[j] = '\0';
	*number = ft_strdup(temp_num);
	free(temp_num);
	*word = ft_strtrim(line + i + 1);
	return (1);
}

static void	parse_and_add_entry(char ***dict, int *line_count, char *buffer)
{
	char	*number;
	char	*word;

	if (parse_line(buffer, &number, &word))
	{
		*dict = realloc(*dict, sizeof(char *) * (*line_count + 2));
		if (!*dict)
			return ;
		(*dict)[*line_count] = ft_strdup(number);
		(*dict)[*line_count + 1] = ft_strdup(word);
		(*line_count) += 2;
		free(number);
		free(word);
	}
}

char	**parse_dictionary(char *dict_path)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	char	**dict;
	int		i;
	int		line_count;

	fd = open(dict_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	dict = NULL;
	i = 0;
	line_count = 0;
	while (read(fd, &buffer[i], 1) > 0)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			parse_and_add_entry(&dict, &line_count, buffer);
			i = 0;
		}
		else
			i++;
	}
	close(fd);
	return (dict);
}