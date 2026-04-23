/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:42:24 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/07 07:42:27 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	not_filled(char **map);

int	ft_no_exit(char **map)
{
	char	**temp;
	int		i;
	int		j;

	temp = ft_copy_map(map);
	temp = ft_f_fill(temp);
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == 'E')
				return (ft_free_2d(temp), 1);
			if (temp[i][j] == 'C')
				return (ft_free_2d(temp), 1);
			j++;
		}
		i++;
	}
	return (ft_free_2d(temp), 0);
}

char	**ft_f_fill(char **map)
{
	int	line_index;
	int	row_index;

	line_index = 0;
	while (map[line_index])
	{
		row_index = 0;
		while (map[line_index][row_index])
		{
			if (map[line_index][row_index] == 'P'
				|| map[line_index][row_index] == 'F')
				map = ft_plus_fill(line_index, row_index, map);
			row_index++;
		}
		line_index++;
	}
	if (not_filled(map))
		map = ft_f_fill(map);
	return (map);
}

static int	not_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i != 0 && map[i][j] == 'F')
			{
				if (map[i + 1][j] != '1' && map[i + 1][j] != 'F')
					return (1);
				if (map[i - 1][j] != '1' && map[i - 1][j] != 'F')
					return (1);
				if (map[i][j + 1] != '1' && map[i][j + 1] != 'F')
					return (1);
				if (map[i][j - 1] != '1' && map[i][j - 1] != 'F')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
