/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:38:40 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 18:33:30 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_value(int *input, int **grid, int row, int column);
int	solvable(int *input);
int	check_vis(int *input, int **grid);

int	solve(int *input, int **grid, int position)
{
	int	row;
	int	column;
	int	i;

	if (!solvable(input))
		return (0);
	i = 1;
	row = position / 4;
	column = position % 4;
	if (position == 16)
		return (!check_vis(input, grid));
	if (grid[row][column] != 0)
		return (solve(input, grid, position + 1));
	while (i <= 4)
	{
		grid[row][column] = i;
		if (valid_value(input, grid, row, column))
		{
			if (solve(input, grid, position + 1))
				return (1);
		}
		grid[row][column] = 0;
		i++;
	}
	return (0);
}
