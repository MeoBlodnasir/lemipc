#include "lemipc.h"

void	init_game(t_shm *shm)
{
  char	*line;
  int		i;

  shm->state = GAMESTATE_INIT;
  ft_memset(shm->m, MAP_BORDERWIDTH, TRUEMAP_WIDTH - 1);
  shm->m[TRUEMAP_WIDTH - 1] = '\n';
  ft_memset(shm->m + sizeof(shm->m) - TRUEMAP_WIDTH, MAP_BORDERWIDTH, TRUEMAP_WIDTH - 1);
  shm->m[sizeof(shm->m) - 1] = '\n';
  i = 0;
  while (i < MAP_HEIGHT)
  {
    line = shm->m + ((i + 1) * TRUEMAP_WIDTH);
    line[0] = MAP_BORDERHEIGHT;
    line[TRUEMAP_WIDTH - 2] = MAP_BORDERHEIGHT;
    line[TRUEMAP_WIDTH - 1] = '\n';
    ft_memset(line + 1, MAP_EMPTYCASE, MAP_WIDTH);
    i += 1;
  }
}

void	shm_link(char **map, t_shm *shm)
{
	int		i;

	i = 0;
	while (i < MAP_HEIGHT)
	{
		map[i] = shm->m + (i + 1) * TRUEMAP_WIDTH + 1;
		i += 1;
	}
}

void	init(t_context *context)
{
	shm_get(&context->shmid, &context->creator);
	shm_attach(&context->shm, context->shmid);
	sem_get(&context->semid, context->creator);
	sem_wait(context->semid);
	shm_link(context->map, context->shm);
	if (context->creator)
	{
		init_game(context->shm);
	}
	sem_post(context->semid);
	mq_get(&context->mqid);
}

void	end(t_context *context, int last_process)
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

void	display(t_shm *shm)
{
  int		i;

  write(1, shm->m, sizeof(shm->m));
  i = -1;
  while (++i <= TRUEMAP_HEIGHT)
    printf("\033[F");
  printf("\n");
}

t_deadly *handle_enemy(t_pos p, char **map, t_deadly *enemy, int *enemy_count)
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
    return enemy;
}

int		isdead(t_player *player, char **map)
{
  static int		delta[][2] = {
    { -1, -1 }, { -1,  0 }, { -1,  1 },
    {  0, -1 }, {  0,  0 }, {  0,  1 },
    {  1, -1 }, {  1,  0 }, {  1,  1 }
  };
  t_pos			p;
  t_deadly		*enemy;
  int				enemy_count;
  int	i;

  enemy = NULL;
  enemy_count = 0;
  i = -1;
  while (++i < (int)(sizeof(delta) / (int)sizeof(delta[0])))
  {
    p.x = player->pos.x + delta[i][0];
    p.y = player->pos.y + delta[i][1];
  fprintf(stderr, "after init\n");
    if (!isoutofrange(p.x, p.y) && isenemy(player, map[p.y][p.x]))
    {
  fprintf(stderr, "begin isead\n");
      enemy = handle_enemy(p, map, enemy, &enemy_count);
    }
  fprintf(stderr, "outside\n");
  }
  i = -1;
  while (++i < enemy_count)
    if (enemy[i].count > 1)
      break ;
  return (i != enemy_count);
}

int		last_team_standing(char **map, char *winner)
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

void	loop(t_context *context)
{
  int		die = 0;
  char	winner;

  while (!die)
  {
    sem_wait(context->semid);
  
    if (context->shm->state != GAMESTATE_INIT &&
        last_team_standing(context->map, &winner))
    {
      die = 1;
    }
    if (context->shm->state == GAMESTATE_OVER ||
        isdead(&context->player, context->map))
      die = 1;
    else if (context->shm->state == GAMESTATE_ON)
      ia(context);
    sem_post(context->semid);
    usleep(200000);
  }
}

void	loop_display(t_context *context)
{
  int		die = 0;
  char	winner;

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

void   handle_start(t_context context)
{
    sem_wait(context.semid);
    context.shm->state = GAMESTATE_ON;
    sem_post(context.semid);
}

void    handle_stop(t_context context)
{
    sem_wait(context.semid);
    context.shm->state = GAMESTATE_OVER;
    sem_post(context.semid);
}

void    handle_general_case(t_context context, char **argv, int *last_process)
{
    sem_wait(context.semid);
    player_init(&context.player, context.map, argv[1][0]);
    sem_post(context.semid);
    loop(&context);
    sem_wait(context.semid);
    *last_process = player_erase(&context.player, context.map, last_process);
    sem_post(context.semid);
}

int		main(int argc, char **argv)
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
