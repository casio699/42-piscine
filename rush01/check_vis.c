/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:35:37 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 17:34:43 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int *line)
{
	int	i;
	int	max_height;
	int	count;
	int	visible[4];

	i = 0;
	max_height = 0;
	count = 0;
	while (i < 4)
	{
		if (line[i] > max_height)
		{
			visible[count++] = line[i];
			max_height = line[i];
		}
		i++;
	}
	return (count);
}

int	check_col_visibility(int *input, int **grid)
{
	int	i;
	int	temp[4];

	i = 0;
	while (i < 4)
	{
		temp[0] = grid[0][i];
		temp[1] = grid[1][i];
		temp[2] = grid[2][i];
		temp[3] = grid[3][i];
		if (count_visible(temp) != input[i])
			return (1);
		temp[0] = grid[3][i];
		temp[1] = grid[2][i];
		temp[2] = grid[1][i];
		temp[3] = grid[0][i];
		if (count_visible(temp) != input[i + 4])
			return (1);
		i++;
	}
	return (0);
}

int	check_row_visibility(int *input, int **grid)
{
	int	i;
	int	temp[4];

	i = 0;
	while (i < 4)
	{
		temp[0] = grid[i][0];
		temp[1] = grid[i][1];
		temp[2] = grid[i][2];
		temp[3] = grid[i][3];
		if (count_visible(temp) != input[i + 8])
			return (1);
		temp[0] = grid[i][3];
		temp[1] = grid[i][2];
		temp[2] = grid[i][1];
		temp[3] = grid[i][0];
		if (count_visible(temp) != input[i + 12])
			return (1);
		i++;
	}
	return (0);
}

int	check_vis(int *input, int **grid)
{
	return (check_col_visibility(input, grid)
		|| check_row_visibility(input, grid));
}
