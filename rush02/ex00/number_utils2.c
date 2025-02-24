/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 04:05:29 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/24 04:05:30 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush02.h"

char	*get_power_word(char **dict, int power)
{
	char	num[37];
	int		i;

	num[0] = '1';
	i = 1;
	while (i <= power)
	{
		num[i] = '0';
		i++;
	}
	num[i] = '\0';
	return (find_exact_match(dict, num));
}

void	append_hundred(char **dict, char *result)
{
	char	*hundred_word;

	hundred_word = find_exact_match(dict, "100");
	if (hundred_word)
	{
		write_word(result, hundred_word, 1);
		free(hundred_word);
	}
}

void	handle_remaining_digits(char **dict, char *num, char *result)
{
	if (num[1] == '1')
		handle_below_20(dict, num + 1, result);
	else if (num[1] != '0' || num[2] != '0')
		handle_tens(dict, num + 1, result);
}

char	*handle_hundreds(char **dict, char *num, char *result)
{
	char	hundreds[2];
	char	*word;

	hundreds[0] = num[0];
	hundreds[1] = '\0';
	word = find_exact_match(dict, hundreds);
	if (word)
	{
		write_word(result, word, ft_strlen(result) > 0);
		free(word);
		append_hundred(dict, result);
	}
	handle_remaining_digits(dict, num, result);
	return (result);
}
