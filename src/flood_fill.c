/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:56:38 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 19:10:00 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	**init_stepped(t_data *game)
{
	int	**stepped;
	int	y;

	y = 0;
	stepped = ft_calloc(game->height, sizeof(int *));
	if (!stepped)
		return (NULL);
	while (y < game->height)
	{
		stepped[y] = ft_calloc(game->width, sizeof(int));
		if (!stepped[y])
		{
			destroy_stepped(stepped, game);
			fd_putstr("Error\nInvalid allocation", 2);
		}
		y++;
	}
	return (stepped);
}

static void	check_chicken(t_data *game, int **stepped)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!stepped[y][x] && (game->map[y][x] == 'E'
				|| game->map[y][x] == 'C'))
			{
				destroy_stepped(stepped, game);
				fd_putstr(
					"Error\nExpired Chicken\n", 2);
				destroy_exit(game);
			}
			x++;
		}
		y++;
	}
}

static void	flood_fill(t_data *game, int **stepped, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->width || y >= game->height)
		return ;
	if (stepped[y][x] || game->map[y][x] == '1')
		return ;
	stepped[y][x] = 1;
	flood_fill(game, stepped, x - 1, y);
	flood_fill(game, stepped, x + 1, y);
	flood_fill(game, stepped, x, y - 1);
	flood_fill(game, stepped, x, y + 1);
}

void	is_accessible(t_data *game)
{
	int	**stepped;

	stepped = NULL;
	stepped = init_stepped(game);
	flood_fill(game, stepped, game->playerx, game->playery);
	check_chicken(game, stepped);
	destroy_stepped(stepped, game);
}
