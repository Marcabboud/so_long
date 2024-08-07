/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:55:08 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 19:10:00 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	moves_log(t_data *game)
{
	fd_putstr("Move count :", 1);
	ft_putnbr(game->moves);
	write(1, "\n", 1);
	show_map(game);
}

static void	new_player_position(t_data *game, int x, int y, char c)
{
	game->moves++;
	game->map[game->playery][game->playerx] = '0';
	game->playerx = x;
	game->playery = y;
	game->map[game->playery][game->playerx] = c;
}

static void	horizontal_moves(t_data *game, int left)
{
	int	x;

	player_position(game);
	if (left == 1)
		x = game->playerx - 1;
	else
		x = game->playerx + 1;
	if (x == game->width || game->map[game->playery][x] == '1')
		return ;
	if (game->map[game->playery][x] == 'C')
		game->cchicken++;
	if (game->map[game->playery][x] == 'E')
	{
		if (game->tchicken == game->cchicken)
			destroy_exit(game);
		else
			return ;
	}
	new_player_position(game, x, game->playery, 'P');
	moves_log(game);
}

static void	vertical_moves(t_data *game, bool up)
{
	int	y;

	player_position(game);
	if (up == true)
		y = game->playery - 1;
	else
		y = game->playery + 1;
	if (y == game->height || game->map[y][game->playerx] == '1')
		return ;
	if (game->map[y][game->playerx] == 'C')
		game->cchicken++;
	if (game->map[y][game->playerx] == 'E')
	{
		if (game->tchicken == game->cchicken)
			destroy_exit(game);
		else
			return ;
	}
	if (game->map[game->playery][game->playerx] == 'L')
		new_player_position(game, game->playerx, y, 'L');
	else
		new_player_position(game, game->playerx, y, 'P');
	moves_log(game);
}

int	keys(int keys, t_data *game)
{
	if (keys == UP || keys == 119)
		vertical_moves(game, 1);
	if (keys == DOWN || keys == 115)
		vertical_moves(game, 0);
	if (keys == LEFT || keys == 97)
		horizontal_moves(game, 1);
	if (keys == RIGHT || keys == 100)
		horizontal_moves(game, 0);
	if (keys == ESC)
		destroy_exit(game);
	if (keys == 121)
	{
		player_position(game);
		if (game->map[game->playery][game->playerx] == 'P')
			game->map[game->playery][game->playerx] = 'Y';
		if (game->map[game->playery][game->playerx] == 'L')
			game->map[game->playery][game->playerx] = 'I';
		show_map(game);
	}
	return (0);
}
