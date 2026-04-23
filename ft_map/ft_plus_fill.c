/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:42:34 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/07 07:42:36 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static char	**ft_fill_right(int line_index, int row_index, char **map);
static char	**ft_fill_left(int line_index, int row_index, char **map);
static char	**ft_fill_up(int line_index, int row_index, char **map);
static char	**ft_fill_down(int line_index, int row_index, char **map);

char	**ft_plus_fill(int line_index, int row_index, char **map)
{
	map = ft_fill_right(line_index, row_index, map);
	map = ft_fill_left(line_index, row_index, map);
	map = ft_fill_up(line_index, row_index, map);
	map = ft_fill_down(line_index, row_index, map);
	return (map);
}

static char	**ft_fill_right(int line_index, int row_index, char **map)
{
	int	i;
	int	j;

	i = line_index;
	j = row_index;
	while (map[i][j] != '1' && map[i][j])
	{
		ft_change_char(i, j, map, 'F');
		j++;
	}
	return (map);
}

static char	**ft_fill_left(int line_index, int row_index, char **map)
{
	int	i;
	int	j;

	i = line_index;
	j = row_index;
	while (map[i][j] != '1' && map[i][j])
	{
		ft_change_char(i, j, map, 'F');
		j--;
	}
	return (map);
}

static char	**ft_fill_up(int line_index, int row_index, char **map)
{
	int	i;
	int	j;

	i = line_index;
	j = row_index;
	while (map[i][j] != '1' && map[i][j])
	{
		ft_change_char(i, j, map, 'F');
		i--;
	}
	return (map);
}

static char	**ft_fill_down(int line_index, int row_index, char **map)
{
	int	i;
	int	j;

	i = line_index;
	j = row_index;
	while (map[i][j] != '1' && map[i][j])
	{
		ft_change_char(i, j, map, 'F');
		i++;
	}
	return (map);
}
