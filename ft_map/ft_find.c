/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:50:04 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/10 09:50:07 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_find_player(t_game *game)
{
	char	**map;
	int		column;
	int		row;

	map = game->map;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'P')
			{
				game->player_row = row;
				game->player_column = column;
				break ;
			}
			column++;
		}
		row++;
	}
}

void	ft_find_exit(t_game *game)
{
	char	**map;
	int		column;
	int		row;

	map = game->map;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'E')
			{
				game->exit_row = row;
				game->exit_column = column;
				break ;
			}
			column++;
		}
		row++;
	}
}

int	ft_player_above_exit(t_game *game)
{
	char	**map;
	int		column;
	int		row;

	map = game->map;
	row = 0;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (map[row][column] == 'E')
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}
