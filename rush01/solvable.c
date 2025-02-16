/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:37:59 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 18:33:07 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solvable(int *input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((input[i] == 4 && input[i + 4] != 1)
			|| (input[i] + input[i + 4] > 5)
			|| (input[i] == 1 && input[i + 4] == 1)
			|| (input[i] == 3 && input[i + 4] == 3))
			return (0);
		if ((input[i + 8] == 4 && input[i + 12] != 1)
			|| (input[i + 8] + input[i + 12] > 5)
			|| (input[i + 8] == 1 && input[i + 12] == 1)
			|| (input[i + 8] == 3 && input[i + 12] == 3))
			return (0);
		i++;
	}
	return (1);
}
