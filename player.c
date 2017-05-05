/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:16:05 by aduban            #+#    #+#             */
/*   Updated: 2017/05/05 18:56:43 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int		player_init(t_player *player, char *map[MAP_HEIGHT], char team)
{
	int		x;
	int		y;
	int		check;

	check = 0;
	while (1)
	{
		x = rand() % MAP_WIDTH;
		y = rand() % MAP_HEIGHT;
		if (map[y][x] == MAP_EMPTYCASE)
		{
			map[y][x] = team;
			break ;
		}
		check++;
		if (check > 100)
			return(-1);
	}
	player->id = team;
	player->pos.x = (unsigned int)x;
	player->pos.y = (unsigned int)y;
	return (1);
}

int		player_erase(t_player *player, char **map, int *last_player)
{
	int		i;
	int		j;

	map[player->pos.y][player->pos.x] = MAP_EMPTYCASE;
	*last_player = 1;
	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			if (!isempty(map[i][j]))
				*last_player = 0;
			j += 1;
		}
		i += 1;
	}
	return (*last_player);
}
