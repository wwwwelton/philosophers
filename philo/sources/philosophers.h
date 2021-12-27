/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:45:19 by wleite            #+#    #+#             */
/*   Updated: 2021/12/27 16:57:07 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_args
{
	unsigned int	number_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	times_must_eat;
	long long		firststamp;
}	t_args;

typedef struct s_philo
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	unsigned int	name;
	unsigned int	meals;
	pthread_t		thread;
	t_args			*args;
}	t_philo;

void	init_args(int argc, char **argv, t_args *args);
void	init_data(t_args *args, pthread_mutex_t **forks, t_philo **philos);
void	init_forks(int n, t_mutex **forks, t_philo **philos);
void	init_philos(int n, t_args *args, t_mutex **forks, t_philo **philos);

void	deinit_philo(int n, t_mutex *forks, t_philo *philos);
void	exit_philo(int n, t_mutex *forks, t_philo *philos, int code);

int		ft_atoi(const char *nptr);

void	*actions(void *ptr);
int		start_philosophers(int n, t_philo *philos);

int		sleep_ms(int time);
long long	timestamp(void);
long long	timenow(long long firststamp);

void	print_args(t_args args);

#endif
