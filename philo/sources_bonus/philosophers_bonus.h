/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:45:19 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 03:07:18 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define TOOK_A_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

typedef struct s_data
{
	int				alone;
	int				number_of_philos;
	int				dinner_is_over;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	long			firststamp;
	sem_t			*writing;
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
int		start_philosophers(int n, t_philo *philos);
long	timenow(long firststamp);
long	timestamp(void);
void	check_args(int argc, char **argv);
void	deinit_philo(t_data *data, sem_t *forks, t_philo *philos);
void	exit_philo(t_data *data, sem_t *forks, t_philo *philos);
void	init_args(int argc, char **argv, t_data *data);
void	init_data(t_data *data, sem_t **forks, t_philo **philos);
void	init_forks(int n, t_data *data, sem_t **forks, t_philo **philos);
void	init_philos(int n, t_data *data, sem_t **forks, t_philo **philos);
void	msleep(int time_in_ms);
void	print_action(t_philo *philo, int action);
void	*actions(void *ptr);
// void	*philosopher_monitor(void *ptr);

int		process_create(pid_t *process, void *(*f)(void *), t_philo *philo);
int		process_join();
void	fork_reopen(t_philo *philo);

#endif