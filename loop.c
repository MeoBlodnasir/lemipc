/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:50:58 by aduban            #+#    #+#             */
/*   Updated: 2017/05/05 16:56:13 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

t_deadly	*handle_enemy(t_pos p, char **map,
		t_deadly *enemy, int *enemy_count)
{
	int j;

	j = -1;
	while (++j < *enemy_count)
		if (enemy[j].team == map[p.y][p.x])
		{
			enemy[j].count += 1;
			break ;
		}
	if (j == *enemy_count)
	{
		enemy = realloc(enemy, sizeof(t_deadly) * (*enemy_count + 1));
		if (!enemy)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		enemy[*enemy_count].team = map[p.y][p.x];
		enemy[*enemy_count].count = 1;
		*enemy_count += 1;
	}
	return (enemy);
}

int			isdead(t_player *player, char **map)
{
	static int		delta[][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{0, -1}, {0, 0}, {0, 1},
		{1, -1}, {1, 0}, {1, 1}
	};
	t_pos			p;
	t_deadly		*enemy;
	int				enemy_count;
	int				i;

	enemy = NULL;
	enemy_count = 0;
	i = -1;
	while (++i < (int)(sizeof(delta) / (int)sizeof(delta[0])))
	{
		p.x = player->pos.x + delta[i][0];
		p.y = player->pos.y + delta[i][1];
		if (!isoutofrange(p.x, p.y) && isenemy(player, map[p.y][p.x]))
			enemy = handle_enemy(p, map, enemy, &enemy_count);
	}
	i = -1;
	while (++i < enemy_count)
		if (enemy[i].count > 1)
			break ;
	return (i != enemy_count);
}

void		loop(t_context *context)
{
	int		die;
	char	winner;

	die = 0;
	while (!die)
	{
		sem_wait(context->semid);
		if (context->shm->state != GAMESTATE_INIT &&
				last_team_standing(context->map, &winner))
			die = 1;
		if (context->shm->state == GAMESTATE_OVER ||
				isdead(&context->player, context->map))
			die = 1;
		else if (context->shm->state == GAMESTATE_ON)
			ia(context);
		sem_post(context->semid);
		usleep(200000);
	}
}

void		display(t_shm *shm)
{
	int		i;

	write(1, shm->m, sizeof(shm->m));
	i = -1;
	while (++i <= TRUEMAP_HEIGHT)
		printf("\033[F");
	printf("\n");
}

void		loop_display(t_context *context)
{
	int		die;
	char	winner;

	die = 0;
	while (!die)
	{
		sem_wait(context->semid);
		if (context->shm->state != GAMESTATE_INIT &&
				last_team_standing(context->map, &winner))
			die = 1;
		display(context->shm);
		sem_post(context->semid);
		usleep(200000);
	}
	fprintf(stderr, "Winner %c\n", winner);
}
