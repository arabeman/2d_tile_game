/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:42:03 by arabeman          #+#    #+#             */
/*   Updated: 2024/05/07 07:42:06 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_open_map(const char *filename)
{
	int	fd;

	if (!ft_strstr(filename, ".ber"))
	{
		ft_putstr_fd("Please provide a \".ber\" file\n", 2);
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	return (fd);
}

char	**ft_create_map(int fd)
{
	char	**map;
	char	*next_line;
	char	*lines;
	int		line;

	map = NULL;
	next_line = get_next_line(fd);
	if (next_line)
		lines = ft_strdup("");
	line = 0;
	while (next_line)
	{
		line++;
		lines = ft_realloc_and_join(lines, next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	if (line)
	{
		map = ft_split(lines, '\n');
		free(lines);
	}
	return (map);
}

int	ft_column(char **map)
{
	return (ft_strlen(map[0]));
}

int	ft_row(char **map)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	return (line);
}

void	ft_free_2d(char **splitted)
{
	int	i;

	i = 0;
	if (splitted)
	{
		while (splitted[i])
			free(splitted[i++]);
	}
	free(splitted);
}
