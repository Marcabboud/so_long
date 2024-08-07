/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:02:54 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 19:07:51 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	map_print(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
	{
		fd_putstr(map[i], 1);
		fd_putstr("\n", 1);
	}
}

static bool	valid_open(char **av)
{
	char	buff[1];
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || read(fd, buff, 1) == -1)
	{
		fd_putstr("Error\nInvalid file\n", 2);
		if (fd >= 0)
			close(fd);
		exit(0);
	}
	close(fd);
	return (true);
}

static bool	valid_ber(char *filename)
{
	char	*ber;
	int		size;
	int		i;

	i = 0;
	ber = ".ber";
	size = ft_strlen(filename);
	if (size < 5)
		return (false);
	size -= 4;
	while (i < 4)
	{
		if (ber[i] != filename[size + i])
			return (false);
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	static t_data	game = {0};
	int				i;

	i = 0;
	if (ac != 2)
	{
		fd_putstr("Error\nWrong map argument\n", 2);
		return (0);
	}
	else if (valid_ber(av[1]))
	{
		valid_open(av);
		map_fill(av[1], &game);
		if (!game.map)
			return (fd_putstr("Error\nInvalid Mapping\n", 2), 0);
		map_print(game.map);
		window(&game);
	}
	else
		fd_putstr("Error\nInvalid file extension name\n", 2);
	return (0);
}
