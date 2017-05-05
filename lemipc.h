/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:31:35 by aduban            #+#    #+#             */
/*   Updated: 2017/05/05 19:34:29 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H
# ifndef _GNU_SOURCE
#  define _GNU_SOURCE 1
# endif

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <time.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <math.h>

# define MAP_WIDTH		60
# define MAP_HEIGHT		20
# define TRUEMAP_HEIGHT	(MAP_HEIGHT + 2)
# define TRUEMAP_WIDTH	(MAP_WIDTH + 3)
# define MAP_SIZE		(TRUEMAP_HEIGHT * TRUEMAP_WIDTH)
# define MAP_BORDERWIDTH	'-'
# define MAP_BORDERHEIGHT	'|'
# define MAP_EMPTYCASE	' '
# define MQNAME_BASIS				"/lemipcteam"
# define MQNAME_BASIS_SIZE	(sizeof("/lemipcteam") - 1)
# define MQNAME_SIZE		(MQNAME_BASIS_SIZE + 1)
# define IPCKEY		0xdeadbeef

typedef struct			s_deadly
{
	char				team;
	int					count;
}						t_deadly;

typedef struct			s_msgbuf
{
	long				mtype;
	char				mtext[128];
}						t_msgbuf;

typedef enum			e_gamestate
{
	GAMESTATE_INIT = 0,
	GAMESTATE_ON,
	GAMESTATE_OVER
}						t_gamestate;

typedef struct			s_lp
{
	int					x;
	int					y;
	int					d;
	char				team;
}						t_lp;

typedef struct			s_shm
{
	t_gamestate			state;
	char				m[MAP_SIZE];
}						t_shm;

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_player
{
	int					prime;
	char				id;
	int					mq;
	t_pos				pos;
}						t_player;

typedef struct			s_context
{
	int					creator;
	int					shmid;
	t_shm				*shm;
	int					semid;
	int					mqid;

	char				*map[MAP_HEIGHT];

	t_player			player;
}						t_context;

void					shm_get(int *shmid, int *created);
void					shm_destroy(int shmid);
void					shm_attach(t_shm **shmaddr, int shmid);
void					shm_detach(void *shmaddr);
void					sem_get(int *semid, int creator);
void					sem_destroy(int semid);
void					sem_wait(int semid);
void					sem_post(int semid);
void					mq_get(int *mqid);
void					mq_destroy(int mqid);
void					mq_send(int mqid, int type, void *msg, size_t msgsize);
ssize_t					mq_recv(int mqid, int type, char *msg, size_t msgsize);
int						player_init(t_player *player,
		char *map[MAP_HEIGHT], char team);
int						player_erase(t_player *player,
		char **map, int *last_player);
void					ia(t_context *context);
int						isempty(char c);
int						isally(t_player *player, char c);
int						isenemy(t_player *player, char c);
int						isoutofrange(int x, int y);
void					random_move(t_player *player,
		char **map, int *x1, int *y1);
void					init(t_context *context);
void					end(t_context *context, int last_process);
void					loop_display(t_context *context);
void					loop(t_context *context);
int						last_team_standing(char **map, char *winner);
void					takeoff_player(t_context *context);
void					place_player(t_context *context);
void					move_x(t_context *context, int x_target);
void					move_y(t_context *context, int y_target);
t_lp					*find_all(char **map, t_player *player,
		int (*test)(t_player *, char), size_t *count);
#endif
