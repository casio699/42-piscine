/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkhoder <ahkhoder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:07:08 by ahkhoder          #+#    #+#             */
/*   Updated: 2025/02/16 16:31:24 by ahkhoder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	valid_input(char *str, int *input);
int	init_grid(int **grid);
int	mem_alloc(int **input, int ***grid);
int	solve(int *input, int **grid, int position);
int	free_grid(int *input, int **grid);
int	print_grid(int **grid);

int	main(int argc, char **argv)
{
	int	*input;
	int	**grid;

	input = NULL;
	grid = NULL;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!mem_alloc(&input, &grid))
		return (1);
	init_grid(grid);
	if (valid_input(argv[1], input))
	{
		if (solve(input, grid, 0))
			print_grid(grid);
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
	free_grid(input, grid);
	return (0);
}
