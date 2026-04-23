/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:44:52 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/10 09:45:04 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void		ft_image_to_render(t_game *game, char tile, int i, int j);
static void	ft_put_p(t_game *game, int i, int j);
static void	ft_put_e(t_game *game, int i, int j);

int	ft_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_row(game->map))
	{
		j = 0;
		while (j < ft_column(game->map))
		{
			ft_image_to_render(game, (game->map)[i][j], i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_image_to_render(t_game *game, char tile, int i, int j)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->asset.wall,
			((j) * game->width), ((i) * game->width));
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->asset.bg,
			((j) * game->width), ((i) * game->width));
	else if (tile == 'P')
		ft_put_p(game, i, j);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->asset.collectible, ((j) * game->width), ((i) * game->width));
	else if (tile == 'E')
		ft_put_e(game, i, j);
}

static void	ft_put_p(t_game *game, int i, int j)
{
	if (game->collected == game->collectible && ft_player_above_exit(game))
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->asset.win,
			((j) * game->width), ((i) * game->width));
		mlx_loop_end(game->mlx_ptr);
	}
	if (!ft_player_above_exit(game))
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->asset.player, ((j) * game->width), ((i) * game->width));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->asset.player_above, ((j) * game->width), ((i) * game->width));
}

static void	ft_put_e(t_game *game, int i, int j)
{
	if (game->collected != game->collectible)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->asset.exit,
			((j) * game->width), ((i) * game->width));
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->asset.exit_open, ((j) * game->width), ((i) * game->width));
}
