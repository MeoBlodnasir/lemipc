/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:55:09 by aduban            #+#    #+#             */
/*   Updated: 2017/05/05 16:56:11 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		end(t_context *context, int last_process)
{
	if (last_process)
	{
		mq_destroy(context->mqid);
		sem_destroy(context->semid);
		shm_detach(context->shm);
		shm_destroy(context->shmid);
	}
	else
	{
		shm_detach(context->shm);
	}
}

int			last_team_standing(char **map, char *winner)
{
	char			team;
	unsigned int	x;
	unsigned int	y;

	team = MAP_EMPTYCASE;
	y = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			if (map[y][x] != MAP_EMPTYCASE)
			{
				if (team == MAP_EMPTYCASE)
					team = map[y][x];
				else if (team != map[y][x])
					return (0);
			}
			x += 1;
		}
		y += 1;
	}
	*winner = team;
	return (1);
}
