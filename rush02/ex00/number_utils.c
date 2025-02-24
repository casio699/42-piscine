/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:05:33 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/24 04:05:34 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	write_word(char *result, char *word, int need_space)
{
	int	len;

	len = ft_strlen(result);
	if (len > 0 && need_space)
		result[len++] = ' ';
	while (*word)
		result[len++] = *word++;
	result[len] = '\0';
}

char	*handle_below_20(char **dict, char *num, char *result)
{
	char	*word;

	word = find_exact_match(dict, num);
	if (word)
	{
		write_word(result, word, ft_strlen(result) > 0);
		free(word);
	}
	return (result);
}

char	*handle_tens(char **dict, char *num, char *result)
{
	char	tens[3];
	char	ones[2];
	char	*word;

	tens[0] = num[0];
	tens[1] = '0';
	tens[2] = '\0';
	word = find_exact_match(dict, tens);
	if (word)
	{
		write_word(result, word, ft_strlen(result) > 0);
		free(word);
	}
	if (num[1] != '0')
	{
		ones[0] = num[1];
		ones[1] = '\0';
		word = find_exact_match(dict, ones);
		if (word)
		{
			write_word(result, word, 1);
			free(word);
		}
	}
	return (result);
}
