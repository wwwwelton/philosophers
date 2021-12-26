/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:45:19 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 03:48:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_args
{
	unsigned int	number_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	times_must_eat;

}	t_args;

typedef struct s_philosopher
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	unsigned int	name;
	pthread_t		thread;
}	t_philosopher;

void	init_philo(pthread_mutex_t **forks, t_philosopher **philos);
void	init_args(int argc, char **argv, t_args *args);
void	init_philosophers(int number_of_philos,
		pthread_mutex_t **forks, t_philosopher **philos);
void	init_forks(int number_of_philos,
		pthread_mutex_t **forks, t_philosopher **philos);

void	deinit_philo(int number_of_philos,
		pthread_mutex_t *forks, t_philosopher *philos);

void	exit_philo(int number_of_philos,
		pthread_mutex_t *forks, t_philosopher *philos, int code);

int		ft_atoi(const char *nptr);
void	ft_free_ptr(void **ptr);

void	print_args(t_args args);

#endif
