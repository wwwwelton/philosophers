/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/29 19:46:09 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_philosophers(int n, t_philo *philos)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	while (++i < n)
		pthread_create(&philos[i].thread, NULL, &actions, &philos[i]);
	pthread_create(&monitor_thread, NULL, &philosopher_monitor, philos);
	i = -1;
	while (++i < n)
		pthread_join(philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
	return (0);
}

static int	all_philos_ate(t_philo *philos)
{
	int	i;
	int	had_dinner;

	had_dinner = 0;
	i = -1;
	while (++i < philos->data->number_of_philos)
	{
		if (philos[i].meals == philos[i].data->times_must_eat)
			had_dinner++;
	}
	if (had_dinner == philos->data->number_of_philos)
		return (1);
	return (0);
}

void	waiter_is_ready(t_philo *philo)
{
	while (!philo->ready)
		;
	if (philo->name % 2)
		msleep(5);
}

void	wait_for_threads(t_philo *philos)
{
	int		i;
	int		threads_started;

	threads_started = 0;
	while (threads_started != philos->data->number_of_philos)
	{
		i = -1;
		threads_started = 0;
		while (++i < philos->data->number_of_philos)
		{
			if (philos[i].started)
				threads_started++;
		}
	}
	philos->data->firststamp = timestamp();
	i = -1;
	while (++i < philos->data->number_of_philos)
		philos[i].ready = 1;
}

void	*philosopher_monitor(void *ptr)
{
	int		i;
	long	current_time;
	long	time_to_die;
	t_philo	*philos;

	philos = (t_philo *)ptr;
	wait_for_threads(philos);
	time_to_die = philos->data->time_to_die;
	while (!all_philos_ate(philos))
	{
		i = -1;
		while (++i < philos->data->number_of_philos)
		{
			current_time = timenow(philos->data->firststamp);
			if ((current_time - philos[i].lastsupper) > time_to_die)
			{
				philos[i].data->dinner_is_over = 1;
				print_action(&philos[i], DIED);
				return (NULL);
			}
		}
	}
	return (NULL);
}
