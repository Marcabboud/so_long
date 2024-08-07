/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:56:03 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 19:10:16 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	load_textures(t_data *game)
{
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./textures/luffy.xpm", &game->img_x, &game->img_y);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/boat.xpm", &game->img_x, &game->img_y);
	game->chicken = mlx_xpm_file_to_image(game->mlx,
			"./textures/chicken.xpm", &game->img_x, &game->img_y);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/sand.xpm", &game->img_x, &game->img_y);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/water.xpm", &game->img_x, &game->img_y);
	if (!game->player || !game->exit
		|| !game->chicken || !game->floor || !game->wall)
	{
		fd_putstr("Error\nImage not initialized properly.\n", 2);
		destroy_exit(game);
	}
}

void	item_input(t_data *game, size_t x, size_t y)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->player, (x * 64), (y * 64));
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->chicken, (x * 64), (y * 64));
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, (x * 64), (y * 64));
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->floor, (x * 64), (y * 64));
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall, (x * 64), (y * 64));
}

void	window(t_data *game)
{
	game->mlx = mlx_init();
	load_textures(game);
	col_count(game);
	player_position(game);
	overall_errors(game);
	is_accessible(game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64,
			game->height * 64, "so_long");
	show_map(game);
	mlx_hook(game->mlx_win, 17, (1L << 17), destroy_exit, game);
	mlx_key_hook(game->mlx_win, keys, game);
	mlx_loop(game->mlx);
}
