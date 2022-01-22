/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:45:19 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 13:39:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define TOOK_A_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

typedef struct s_data
{
	int				alone;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	long			firststamp;
	sem_t			*lock_print;
}	t_data;

typedef struct s_philo
{
	int				name;
	int				meals;
	long			lastsupper;
	pid_t			process;
	sem_t			*fork_left;
	sem_t			*fork_right;
	sem_t			*forks;
	t_data			*data;
	void			*philos;
}	t_philo;

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
int		actions(void *ptr);
int		process_create(pid_t *process, int (*f)(void *), t_philo *philo);
int		process_join(t_philo *philos);
int		start_philosophers(int n, t_philo *philos);
long	timenow(long firststamp);
long	timestamp(void);
void	check_args(int argc, char **argv);
void	deinit_philo(t_data *data, sem_t *forks, t_philo *philos);
void	exit_philo(t_data *data, sem_t *forks, t_philo *philos, int exit_code);
void	init_args(int argc, char **argv, t_data *data);
void	init_data(t_data *data, sem_t **forks, t_philo **philos);
void	init_forks(int n, t_data *data, sem_t **forks, t_philo **philos);
void	init_philos(int n, t_data *data, sem_t **forks, t_philo **philos);
void	dsleep(int time_in_ms, t_philo *philo);
void	msleep(int time_in_ms);
void	sem_try_wait(t_philo *philo);
void	print_action(t_philo *philo, int action);

#endif
