/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:42:14 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/07 07:42:16 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	element_invalid(char **map)
{
	int	line;
	int	row;

	line = 0;
	while (map[line])
	{
		row = 0;
		while (map[line][row])
		{
			if (map[line][row] != '0' && map[line][row] != '1'
				&& map[line][row] != 'C' && map[line][row] != 'E'
				&& map[line][row] != 'P')
			{
				return (1);
			}
			row++;
		}
		line++;
	}
	return (0);
}

int	count_invalid(char **map)
{
	int	row_column[2];
	int	p_e_c[3];

	row_column[0] = 0;
	p_e_c[0] = 0;
	p_e_c[1] = 0;
	p_e_c[2] = 0;
	while (map[row_column[0]])
	{
		row_column[1] = 0;
		while (map[row_column[0]][row_column[1]])
		{
			if (map[row_column[0]][row_column[1]] == 'P')
				p_e_c[0]++;
			if (map[row_column[0]][row_column[1]] == 'E')
				p_e_c[1]++;
			if (map[row_column[0]][row_column[1]] == 'C')
				p_e_c[2]++;
			row_column[1]++;
		}
		row_column[0]++;
	}
	if (p_e_c[2] < 1 || p_e_c[1] != 1 || p_e_c[0] != 1)
		return (1);
	return (0);
}

int	form_invalid(char **map)
{
	int	row;
	int	line;

	row = ft_strlen(map[0]);
	line = 0;
	while (map[line])
	{
		if (ft_strlen(map[line]) != row)
			return (1);
		line++;
	}
	return (0);
}

int	wall_unlocked(char **map)
{
	int	column;
	int	row;

	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (row == 0 && map[row][column] != '1')
				return (1);
			if (!map[row + 1] && map[row][column] != '1')
				return (1);
			if (map[row][0] != '1')
				return (1);
			if (!map[row][column + 1] && map[row][column] != '1')
				return (1);
			column++;
		}
		row++;
	}
	return (0);
}

int	map_invalid(char **map)
{
	if (!map)
		return (ft_putstr_fd("Error: Map is empty\n", 2), 1);
	else if (element_invalid(map))
		return (ft_putstr_fd("Error: Invalid tile detected\n", 2), 1);
	else if (count_invalid(map))
		return (ft_putstr_fd("Error: Tile deficiency or excess in the map\n",
				2), 1);
	else if (form_invalid(map))
		return (ft_putstr_fd("Error: Map not rectangular\n", 2), 1);
	else if (wall_unlocked(map))
		return (ft_putstr_fd("Error: No surrounding walls\n", 2), 1);
	else if (ft_no_exit(map))
		return (ft_putstr_fd("Error: Map impossible to complete\n", 2), 1);
	return (0);
}
