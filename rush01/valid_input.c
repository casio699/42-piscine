/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:40:11 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 13:40:12 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_input(char *str, int *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (j >= 16)
				return (0);
			input[j++] = str[i] - '0';
		}
		else if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	if (j != 16)
		return (0);
	return (1);
}
