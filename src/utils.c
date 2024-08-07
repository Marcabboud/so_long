/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabboud <mabboud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:55:15 by mabboud           #+#    #+#             */
/*   Updated: 2024/08/06 17:17:17 by mabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

void	fd_putstr(char *str, int fd)
{
	if (!str)
		return ;
	write(fd, str, ft_strlen(str));
}

void	ft_putnbr(int nbr)
{
	char	x;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	x = (nbr % 10) + '0';
	write(1, &x, 1);
}

static void	*ft_memset(void *s1, int a, size_t n)
{
	unsigned char		*str;
	size_t				i;

	str = (unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char) a;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	total;

	tab = NULL;
	total = (count * size);
	if (count != 0 && ((count * size) / count != size))
		return (NULL);
	tab = malloc(total);
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, total);
	return (tab);
}
