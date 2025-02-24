/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_written_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:05:39 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/24 04:32:32 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*   Updated: 2025/02/24 02:27:02 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_written_form.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 02:56:46 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/24 03:00:45 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

void convert_group(char **dict, char *group, char *result, int power)
{
    char    *power_word;
    int     need_power;
    char    single[2];
    char    teen[3];
    char    tens[3];
    char    ones[2];

    need_power = 0;
    single[1] = '\0';
    teen[2] = '\0';
    tens[2] = '\0';
    ones[1] = '\0';

    /* Handle hundreds place */
    if (group[0] != '0')
    {
        need_power = 1;
        single[0] = group[0];
        char *word = find_exact_match(dict, single);
        if (word)
        {
            write_word(result, word, ft_strlen(result) > 0);
            free(word);
        }
        /* Write "hundred" */
        word = find_exact_match(dict, "100");
        if (word)
        {
            write_word(result, word, 1);
            free(word);
        }
    }
    /* Handle tens and ones */
    if (group[1] != '0' || group[2] != '0')
    {
        need_power = 1;
        if (group[1] == '1')  /* Numbers 10-19 */
        {
            teen[0] = group[1];
            teen[1] = group[2];
            char *word = find_exact_match(dict, teen);
            if (word)
            {
                write_word(result, word, ft_strlen(result) > 0);
                free(word);
            }
        }
        else  /* Other numbers */
        {
            /* Handle tens place if not zero */
            if (group[1] != '0')
            {
                tens[0] = group[1];
                tens[1] = '0';
                char *word = find_exact_match(dict, tens);
                if (word)
                {
                    write_word(result, word, ft_strlen(result) > 0);
                    free(word);
                }
                /* Handle ones place if not zero */
                if (group[2] != '0')
                {
                    ones[0] = group[2];
                    word = find_exact_match(dict, ones);
                    if (word)
                    {
                        write_word(result, word, 1);
                        free(word);
                    }
                }
            }
            else if (group[2] != '0')  /* Only ones place */
            {
                ones[0] = group[2];
                char *word = find_exact_match(dict, ones);
                if (word)
                {
                    write_word(result, word, ft_strlen(result) > 0);
                    free(word);
                }
            }
        }
    }
    /* Add power word (thousand, million, etc.) if this group is not empty */
    if (power > 0 && need_power)
    {
        power_word = get_power_word(dict, power * 3);
        if (power_word)
        {
            write_word(result, power_word, 1);
            free(power_word);
        }
    }
}

void extract_group(char *number, int start, int size, char *group)
{
    int i;

    /* Initialize group with zeros */
    i = 0;
    while (i < 3)
    {
        group[i] = '0';
        i++;
    }
    /* Copy the actual digits from the end of the group */
    i = 0;
    while (i < size)
    {
        group[2 - i] = number[start + size - 1 - i];
        i++;
    }
    group[3] = '\0';
}

void process_groups(char **dict, char *number, char *result, int groups)
{
    int     i;
    int     num_len;
    int     start;
    int     size;
    char    group[4];

    num_len = ft_strlen(number);
    i = 0;
    while (i <= groups)
    {
        /* Calculate the start position and size for this group */
        start = i * 3;
        size = (i == groups) ? (num_len - (groups * 3)) : 3;

        if (size > 0)
        {
            extract_group(number, start, size, group);
            convert_group(dict, group, result, groups - i);
        }
        i++;
    }
}

char *get_written_form(char **dict, char *number)
{
    char    *result;
    int     len;
    int     groups;

    if (!is_valid_number(number))
        return (NULL);

    result = malloc(sizeof(char) * MAX_NUM_LEN);
    if (!result)
        return (NULL);
    result[0] = '\0';

    if (ft_strcmp(number, "0") == 0)
        return (handle_below_20(dict, number, result));

    len = ft_strlen(number);
    groups = (len - 1) / 3;
    process_groups(dict, number, result, groups);

    return (result);
}

/*
#include "ft_rush02.h"

void	convert_group(char **dict, char *group, char *result, int power)
{
	char	*power_word;

	if (ft_strcmp(group, "000") == 0)
		return ;
	if (ft_strlen(group) == 3 && group[0] != '0')
		handle_hundreds(dict, group, result);
	else if (ft_strlen(group) == 2 && group[0] == '1')
		handle_below_20(dict, group, result);
	else if (ft_strlen(group) == 2)
		handle_tens(dict, group, result);
	else
		handle_below_20(dict, group, result);
	if (power > 0 && ft_strcmp(group, "000") != 0)
	{
		power_word = get_power_word(dict, power);
		if (power_word)
		{
			write_word(result, power_word, 1);
			free(power_word);
		}
	}
}

void	extract_group(char *number, int start, int size, char *group)
{
	int	i;

	i = 0;
	while (i < size)
	{
		group[i] = number[start + i];
		i++;
	}
	group[i] = '\0';
}

void	get_group_info(int len, int i, int *start, int *size)
{
	*start = len - (i * 3) - 3;
	if (*start < 0)
	{
		*size = 3 + *start;
		*start = 0;
	}
	else
		*size = 3;
}

void	process_groups(char **dict, char *number, char *result, int groups)
{
	int		i;
	int		start;
	int		size;
	char	group[4];

	i = groups;
	while (i >= 0)
	{
		get_group_info(ft_strlen(number), i, &start, &size);
		extract_group(number, start, size, group);
		convert_group(dict, group, result, i * 3);
		i--;
	}
}

char	*get_written_form(char **dict, char *number)
{
	char	*result;
	int		len;
	int		groups;

	if (!is_valid_number(number))
		return (NULL);
	result = malloc(sizeof(char) * MAX_NUM_LEN);
	if (!result)
		return (NULL);
	result[0] = '\0';
	len = ft_strlen(number);
	if (len == 1 || (len == 2 && number[0] == '1'))
		return (handle_below_20(dict, number, result));
	if (len == 2)
		return (handle_tens(dict, number, result));
	groups = (len - 1) / 3;
	process_groups(dict, number, result, groups);
	return (result);
}*/
