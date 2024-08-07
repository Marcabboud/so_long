/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:57:04 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 15:59:45 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static bool	player(t_data *game, int x, int y)
{
	if (game->map[y][x] == 'P' || game->map[y][x] == 'L'
		|| game->map[y][x] == 'I' || game->map[y][x] == 'Y')
	{
		game->playery = y;
		game->playerx = x;
		return (true);
	}
	return (false);
}

void	player_position(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	if (game == NULL || game->map == NULL)
	{
		fd_putstr("Error\nInvalid Map\n", 2);
		destroy_exit(game);
	}
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (player(game, x, y))
				return ;
			x++;
		}
		y++;
	}
	fd_putstr("Error\nInvalid player\n", 2);
	destroy_exit(game);
}

void	show_map(t_data *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			item_input(game, x, y);
			x++;
		}
		y++;
	}
}
