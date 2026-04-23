/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:44:20 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/10 09:49:07 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		mlx_loop_end(game->mlx_ptr);
	if (keysym == 119)
		ft_move_up(game);
	if (keysym == 115)
		ft_move_down(game);
	if (keysym == 97)
		ft_move_left(game);
	if (keysym == 100)
		ft_move_right(game);
	return (0);
}

int	ft_exit_game(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

void	ft_count_movement(t_game *game)
{
	game->movement++;
	ft_printf("Dancing around with %d movements.💃\n", game->movement);
}
