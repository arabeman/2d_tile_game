/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:41:50 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/07 07:41:58 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	**ft_copy_map(char **map)
{
	int		map_line;
	char	**new_map;
	int		i;
	int		rows;
	int		column;

	map_line = ft_row(map);
	new_map = (char **)malloc(sizeof(char *) * (ft_row(map) + 1));
	i = 0;
	while (i < ft_row(map))
		new_map[i++] = (char *)malloc(sizeof(char) * (ft_column(map) + 1));
	rows = 0;
	while (map[rows])
	{
		column = 0;
		while (map[rows][column])
		{
			new_map[rows][column] = map[rows][column];
			column++;
		}
		new_map[rows][column] = '\0';
		rows++;
	}
	new_map[rows] = NULL;
	return (new_map);
}
