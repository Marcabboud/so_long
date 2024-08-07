/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:57:51 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 19:10:21 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	void	*player;
	void	*chicken;
	void	*exit;
	void	*floor;
	void	*wall;
	int		tchicken;
	int		texit;
	int		cchicken;
	int		moves;
	int		row;
	int		playerx;
	int		playery;
	int		img_y;
	int		img_x;
	int		width;
	int		height;
}	t_data;

void		window(t_data *game);

char		*get_next_line(int fd);

void		fd_putstr(char *str, int fd);

void		*ft_calloc(size_t count, size_t size);

void		is_accessible(t_data *game);

void		fd_putstr(char *s, int fd);

int			ft_strlen(char *str);

void		ft_putnbr(int n);

void		overall_errors(t_data *game);

int			keys(int keys, t_data *game);

void		player_position(t_data *game);

void		col_count(t_data *game);

void		free_map(char **map);

int			destroy_exit(t_data *game);

void		map_fill(char *av, t_data *game);

void		destroy_stepped(int **stepped, t_data *game);

void		item_input(t_data *game, size_t x, size_t y);

void		show_map(t_data *game);

#endif
