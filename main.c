/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:43:19 by aduban            #+#    #+#             */
/*   Updated: 2017/05/05 19:03:45 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void		handle_start(t_context context)
{
	sem_wait(context.semid);
	context.shm->state = GAMESTATE_ON;
	sem_post(context.semid);
}

void		handle_stop(t_context context)
{
	sem_wait(context.semid);
	context.shm->state = GAMESTATE_OVER;
	sem_post(context.semid);
}

void		handle_general_case(t_context context,
		char **argv, int *last_process)
{
	int c;

	sem_wait(context.semid);
	c = player_init(&context.player, context.map, argv[1][0]);
	sem_post(context.semid);
	if (c == -1)
		return ;;
	loop(&context);
	sem_wait(context.semid);
	*last_process = player_erase(&context.player, context.map, last_process);
	sem_post(context.semid);
}

int			main(int argc, char **argv)
{
	t_context	context;
	int			last_process;

	last_process = 0;
	if (argc != 2)
	{
		printf("Only specify team id\n");
		return (2);
	}
	srand((unsigned int)time(NULL));
	init(&context);
	if (!ft_strcmp(argv[1], "start"))
		handle_start(context);
	else if (!ft_strcmp(argv[1], "stop"))
		handle_stop(context);
	else if (!ft_strcmp(argv[1], "display"))
		loop_display(&context);
	else
	{
		handle_general_case(context, argv, &last_process);
	}
	end(&context, last_process);
	return (0);
}
