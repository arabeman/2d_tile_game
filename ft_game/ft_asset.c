/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:43:53 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/10 09:44:05 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	asset_64x64(t_game *game);
void	asset_32x32(t_game *game);
void	asset_16x16(t_game *game);

void	ft_get_assets(t_game *game)
{
	if (ft_column(game->map) > 60 || ft_row(game->map) > 32)
	{
		asset_16x16(game);
	}
	else if (ft_column(game->map) > 30 || ft_row(game->map) > 16)
	{
		asset_32x32(game);
	}
	else
	{
		asset_64x64(game);
	}
}

void	ft_free_assets(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->asset.wall);
	mlx_destroy_image(game->mlx_ptr, game->asset.bg);
	mlx_destroy_image(game->mlx_ptr, game->asset.player);
	mlx_destroy_image(game->mlx_ptr, game->asset.player_above);
	mlx_destroy_image(game->mlx_ptr, game->asset.exit);
	mlx_destroy_image(game->mlx_ptr, game->asset.exit_open);
	mlx_destroy_image(game->mlx_ptr, game->asset.collectible);
	mlx_destroy_image(game->mlx_ptr, game->asset.win);
}

void	asset_64x64(t_game *game)
{
	game->asset.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/64/wall.xpm", &game->width, &game->height);
	game->asset.bg = mlx_xpm_file_to_image(game->mlx_ptr, "assets/64/tiles.xpm",
			&game->width, &game->height);
	game->asset.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/64/player.xpm", &game->width, &game->height);
	game->asset.player_above = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/64/player_door.xpm", &game->width, &game->height);
	game->asset.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/64/door.xpm", &game->width, &game->height);
	game->asset.exit_open = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/64/stair.xpm", &game->width, &game->height);
	game->asset.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/64/key.xpm", &game->width, &game->height);
	game->asset.win = mlx_xpm_file_to_image(game->mlx_ptr, "assets/64/win.xpm",
			&game->width, &game->height);
}

void	asset_32x32(t_game *game)
{
	game->asset.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/32/wall.xpm", &game->width, &game->height);
	game->asset.bg = mlx_xpm_file_to_image(game->mlx_ptr, "assets/32/tiles.xpm",
			&game->width, &game->height);
	game->asset.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/32/player.xpm", &game->width, &game->height);
	game->asset.player_above = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/32/player_door.xpm", &game->width, &game->height);
	game->asset.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/32/door.xpm", &game->width, &game->height);
	game->asset.exit_open = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/32/stair.xpm", &game->width, &game->height);
	game->asset.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/32/key.xpm", &game->width, &game->height);
	game->asset.win = mlx_xpm_file_to_image(game->mlx_ptr, "assets/32/win.xpm",
			&game->width, &game->height);
}

void	asset_16x16(t_game *game)
{
	game->asset.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/16/wall.xpm", &game->width, &game->height);
	game->asset.bg = mlx_xpm_file_to_image(game->mlx_ptr, "assets/16/tiles.xpm",
			&game->width, &game->height);
	game->asset.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/16/player.xpm", &game->width, &game->height);
	game->asset.player_above = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/16/player_door.xpm", &game->width, &game->height);
	game->asset.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/16/door.xpm", &game->width, &game->height);
	game->asset.exit_open = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/16/stair.xpm", &game->width, &game->height);
	game->asset.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/16/key.xpm", &game->width, &game->height);
	game->asset.win = mlx_xpm_file_to_image(game->mlx_ptr, "assets/16/win.xpm",
			&game->width, &game->height);
}
