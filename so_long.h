/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:12:11 by arabeman          #+#    #+#             */
/*   Updated: 2024/04/26 15:12:12 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_asset
{
	void	*wall;
	void	*bg;
	void	*collectible;
	void	*player;
	void	*exit;
	void	*exit_open;
	void	*player_above;
	void	*win;
}			t_asset;

typedef struct s_game
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		line;
	int		row;
	t_asset	asset;
	char	**map;
	int		player_row;
	int		player_column;
	int		exit_row;
	int		exit_column;
	int		collectible;
	int		collected;
	int		movement;
}			t_game;

int			element_invalid(char **map);
int			count_invalid(char **map);
int			form_invalid(char **map);
int			wall_unlocked(char **map);
int			map_invalid(char **map);

char		**ft_create_map(int fd);
void		ft_free_2d(char **splitted);
int			ft_open_map(const char *filename);
int			ft_row(char **map);
int			ft_column(char **map);

char		**ft_plus_fill(int line_index, int row_index, char **map);
char		**ft_f_fill(char **map);
char		**ft_copy_map(char **map);
void		ft_change_char(int row_index, int column_index, char **map, char c);
int			ft_no_exit(char **map);
void		ft_count_collectible(t_game *game);

void		ft_init_game(t_game *game, int fd);
void		ft_free_game(t_game *game);
void		ft_check_win(t_game *game);

void		ft_get_assets(t_game *game);
void		ft_free_assets(t_game *game);

int			handle_keypress(int keysym, t_game *game);
int			ft_exit_game(t_game *game);
void		ft_count_movement(t_game *game);

int			ft_render(t_game *game);

void		ft_find_player(t_game *game);
void		ft_find_exit(t_game *game);
int			ft_player_above_exit(t_game *game);

void		ft_move_up(t_game *game);
void		ft_move_down(t_game *game);
void		ft_move_left(t_game *game);
void		ft_move_right(t_game *game);

#endif
