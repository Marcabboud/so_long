/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FandD.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:56:21 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 19:03:48 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	destroy_exit(t_data *game)
{
	int	i;

	i = 0;
	free_map(game->map);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->chicken)
		mlx_destroy_image(game->mlx, game->chicken);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	destroy_stepped(int **stepped, t_data *game)
{
	int	y;

	y = 0;
	while (y < game->height)
		free(stepped[y++]);
	free(stepped);
}
