/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 15:45:30 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_philosophers(int n, t_philo *philos)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	philos->data->firststamp = timestamp();
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
		if (get_meals(&philos[i]) == philos[i].data->times_must_eat)
			had_dinner++;
	}
	if (had_dinner == philos->data->number_of_philos)
		return (1);
	return (0);
}

void	*philosopher_monitor(void *ptr)
{
	int		i;
	long	current_time;
	long	time_to_die;
	t_philo	*philos;

	philos = (t_philo *)ptr;
	time_to_die = philos->data->time_to_die;
	while (!all_philos_ate(philos))
	{
		i = -1;
		while (++i < philos->data->number_of_philos)
		{
			current_time = timenow(philos->data->firststamp);
			if ((current_time - get_lastsupper(&philos[i])) > time_to_die)
			{
				finish_dinner(&philos[i]);
				print_action(&philos[i], DIED);
				return (NULL);
			}
		}
		msleep(1);
	}
	return (NULL);
}
