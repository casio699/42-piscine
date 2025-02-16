/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:40:29 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 18:23:16 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_visibility(int *input, int **grid);
int	check_row_visibility(int *input, int **grid);
int	count_visible(int *line);

int	check_duplicate(int **grid, int row, int column)
{
	int	i;
	int	num;

	num = grid[row][column];
	if (num == 0)
		return (1);
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num && i != column)
			return (0);
		if (grid[i][column] == num && i != row)
			return (0);
		i++;
	}
	return (1);
}

int	check_row(int *input, int **grid, int row)
{
	int	temp[4];
	int	temp_rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		temp[i] = grid[row][i];
		i++;
	}
	if (count_visible(temp) != input[row + 8])
		return (0);
	i = 0;
	while (i < 4)
	{
		temp_rev[i] = temp[3 - i];
		i++;
	}
	return (count_visible(temp_rev) == input[row + 12]);
}

int	check_col(int *input, int **grid, int col)
{
	int	temp[4];
	int	temp_rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		temp[i] = grid[i][col];
		i++;
	}
	if (count_visible(temp) != input[col])
		return (0);
	i = 0;
	while (i < 4)
	{
		temp_rev[i] = temp[3 - i];
		i++;
	}
	return (count_visible(temp_rev) == input[col + 4]);
}

int	valid_value(int *input, int **grid, int row, int col)
{
	int	complete_row;
	int	complete_col;
	int	i;

	if (!check_duplicate(grid, row, col))
		return (0);
	i = 0;
	complete_row = 1;
	complete_col = 1;
	while (i < 4)
	{
		if (grid[row][i] == 0)
			complete_row = 0;
		if (grid[i][col] == 0)
			complete_col = 0;
		i++;
	}
	if (complete_row && !check_row(input, grid, row))
		return (0);
	if (complete_col && !check_col(input, grid, col))
		return (0);
	return (1);
}
