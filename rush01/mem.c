/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:11:08 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 18:35:23 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include <unistd.h>

int	write_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	init_grid(int **grid)
{
	int	i;
	int	j;

	if (!grid)
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
		i++;
	}
	return (1);
}

int	alloc_rows(int ***grid, int i)
{
	while (i < 4)
	{
		(*grid)[i] = (int *)malloc(4 * sizeof(int));
		if (!(*grid)[i])
			return (0);
		i++;
	}
	return (1);
}

int	mem_alloc(int **input, int ***grid)
{
	int	i;
	int	j;

	*input = (int *)malloc(16 * sizeof(int));
	if (!*input)
		write_error();
	*grid = (int **)malloc(4 * sizeof(int *));
	if (!*grid)
	{
		free(*input);
		write_error();
	}
	if (!alloc_rows(grid, 0))
	{
		i = 0;
		j = 0;
		while (j < i)
			free((*grid)[j++]);
		free(*grid);
		free(*input);
		write_error();
	}
	return (1);
}

int	free_grid(int *input, int **grid)
{
	int	i;

	if (grid)
	{
		i = 0;
		while (i < 4)
		{
			if (grid[i])
				free(grid[i]);
			i++;
		}
		free(grid);
	}
	if (input)
		free(input);
	return (0);
}
