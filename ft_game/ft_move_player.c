/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:48:49 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/10 09:49:38 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_move_up(t_game *game)
{
	int	row;
	int	column;

	ft_find_player(game);
	row = game->player_row;
	column = game->player_column;
	if (game->map[row - 1][column] != '1')
	{
		if (game->map[row - 1][column] == 'C')
			game->collected++;
		ft_change_char(row - 1, column, game->map, 'P');
		if (row == game->exit_row && column == game->exit_column)
			ft_change_char(row, column, game->map, 'E');
		else
			ft_change_char(row, column, game->map, '0');
		ft_count_movement(game);
	}
}

void	ft_move_down(t_game *game)
{
	int	row;
	int	column;

	ft_find_player(game);
	row = game->player_row;
	column = game->player_column;
	if (game->map[row + 1][column] != '1')
	{
		if (game->map[row + 1][column] == 'C')
			game->collected++;
		ft_change_char(row + 1, column, game->map, 'P');
		if (row == game->exit_row && column == game->exit_column)
			ft_change_char(row, column, game->map, 'E');
		else
			ft_change_char(row, column, game->map, '0');
		ft_count_movement(game);
	}
}

void	ft_move_left(t_game *game)
{
	int	row;
	int	column;

	ft_find_player(game);
	row = game->player_row;
	column = game->player_column;
	if (game->map[row][column - 1] != '1')
	{
		if (game->map[row][column - 1] == 'C')
			game->collected++;
		ft_change_char(row, column - 1, game->map, 'P');
		if (row == game->exit_row && column == game->exit_column)
			ft_change_char(row, column, game->map, 'E');
		else
			ft_change_char(row, column, game->map, '0');
		ft_count_movement(game);
	}
}

void	ft_move_right(t_game *game)
{
	int	row;
	int	column;

	ft_find_player(game);
	row = game->player_row;
	column = game->player_column;
	if (game->map[row][column + 1] != '1')
	{
		if (game->map[row][column + 1] == 'C')
			game->collected++;
		ft_change_char(row, column + 1, game->map, 'P');
		if (row == game->exit_row && column == game->exit_column)
			ft_change_char(row, column, game->map, 'E');
		else
			ft_change_char(row, column, game->map, '0');
		ft_count_movement(game);
	}
}
