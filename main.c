/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:12:00 by arabeman          #+#    #+#             */
/*   Updated: 2024/04/26 15:12:04 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	arg_invalid(int argc);

int	main(int argc, char const *argv[])
{
	int		fd;
	t_game	game;

	if (argc == 2)
	{
		fd = ft_open_map(argv[1]);
		ft_init_game(&game, fd);
		mlx_loop_hook(game.mlx_ptr, &ft_render, &game);
		mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game);
		mlx_hook(game.win_ptr, 17, 0, ft_exit_game, &game);
		mlx_loop(game.mlx_ptr);
		ft_check_win(&game);
		ft_free_game(&game);
	}
	else
		arg_invalid(argc);
	exit(0);
}

void	arg_invalid(int argc)
{
	if (argc == 1)
		ft_putstr_fd("Missing second argument\n", 2);
	else
		ft_putstr_fd("Too many arguments provided\n", 2);
}
