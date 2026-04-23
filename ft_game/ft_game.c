/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:43:31 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/10 09:43:33 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	verify_map(char **map);

void	ft_init_game(t_game *game, int fd)
{
	int	pixels;

	pixels = 64;
	game->fd = fd;
	game->map = ft_create_map(game->fd);
	verify_map(game->map);
	if (ft_column(game->map) > 30 || ft_row(game->map) > 16)
		pixels = 32;
	if (ft_column(game->map) > 60 || ft_row(game->map) > 32)
		pixels = 16;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, pixels * ft_column(game->map),
			pixels * ft_row(game->map), "So_long");
	game->width = pixels;
	game->height = pixels;
	game->collected = 0;
	game->movement = 0;
	ft_count_collectible(game);
	ft_get_assets(game);
	ft_find_player(game);
	ft_find_exit(game);
}

void	ft_free_game(t_game *game)
{
	close(game->fd);
	ft_free_2d(game->map);
	ft_free_assets(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

void	ft_check_win(t_game *game)
{
	if (game->collected == game->collectible && ft_player_above_exit(game))
		ft_printf("You WIN! That's...great. 😄\n\n");
	else
		ft_printf("It seems you've abandoned. How unexpected. 😏\n\n");
}

void	verify_map(char **map)
{
	if (map_invalid(map))
	{
		if (map)
			ft_free_2d(map);
		exit(1);
	}
}
