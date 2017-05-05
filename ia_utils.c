/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:58:56 by aduban            #+#    #+#             */
/*   Updated: 2017/05/05 17:01:48 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

int			lpcmp(void const *a, void const *b)
{
	t_lp	*p1;
	t_lp	*p2;

	p1 = (t_lp *)a;
	p2 = (t_lp *)b;
	return ((int)p1->d - (int)p2->d);
}

void		err_and_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void		get_distance(t_lp *p, char **map, t_player *player)
{
	int x;
	int y;

	p->team = map[p->y][p->x];
	x = (int)p->x - (int)player->pos.x;
	y = (int)p->y - (int)player->pos.y;
	p->d = (unsigned int)sqrt(x * x + y * y);
}

t_lp		*find_all(char **map, t_player *player,
		int (*test)(t_player *, char), size_t *count)
{
	t_lp			*ps;
	size_t			pcount;
	t_lp			p;

	ps = NULL;
	pcount = 0;
	p.y = -1;
	while (++p.y < MAP_HEIGHT)
	{
		p.x = -1;
		while (++p.x < MAP_WIDTH)
			if (!(p.x == player->pos.x && p.y == player->pos.y) &&
					test(player, map[p.y][p.x]))
			{
				if (!(ps = realloc(ps, (pcount + 1) * sizeof(t_lp))))
					err_and_exit("realloc");
				get_distance(&p, map, player);
				ps[pcount] = p;
				pcount += 1;
			}
	}
	qsort(ps, pcount, sizeof(t_lp), &lpcmp);
	*count = pcount;
	return (ps);
}
