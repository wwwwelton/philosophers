/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:45:19 by wleite            #+#    #+#             */
/*   Updated: 2021/12/29 03:05:32 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;

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
	pthread_mutex_t	*writing;
}	t_data;

typedef struct s_philo
{
	int				name;
	int				meals;
	long			lastsupper;
	pthread_t		thread;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_data			*data;
}	t_philo;

int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		ft_isdigit(int c);
int		msleep(int time);
int		start_philosophers(int n, t_philo *philos);
long	timenow(long firststamp);
long	timestamp(void);
void	check_args(int argc, char **argv);
void	deinit_philo(int n, t_mutex *forks, t_philo *philos);
void	exit_philo(int n, t_mutex *forks, t_philo *philos);
void	init_args(int argc, char **argv, t_data *data);
void	init_data(t_data *data, pthread_mutex_t **forks, t_philo **philos);
void	init_forks(int n, t_mutex **forks, t_philo **philos);
void	init_philos(int n, t_data *data, t_mutex **forks, t_philo **philos);
void	print_action(t_philo *philo, int action);
void	try_lock(t_philo *philo);
void	*actions(void *ptr);
void	*philosopher_monitor(void *ptr);

#endif
