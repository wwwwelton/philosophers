/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/27 22:57:27 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_philosophers(int n, t_philo *philos)
{
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	while (++i < n)
	{
		pthread_create(&philos[i].thread, NULL, &actions, &philos[i]);
		msleep(10);
	}
	pthread_create(&monitor_thread, NULL, &philosopher_monitor, philos);
	pthread_join(monitor_thread, NULL);
	i = -1;
	while (++i < n)
		pthread_join(philos[i].thread, NULL);
	return (0);
}

void	print_action(t_philo *philo, int action)
{
	long long	current_time;

	current_time = timenow(philo->args->firststamp);
	pthread_mutex_lock(philo->args->writing);
	if (action == TOOK_A_FORK)
		printf("%5lld %3d has taken a fork\n", current_time, philo->name);
	else if (action == EATING)
		printf("%5lld %3d is eating\n", current_time, philo->name);
	else if (action == SLEEPING)
		printf("%5lld %3d is sleeping\n", current_time, philo->name);
	else if (action == THINKING)
		printf("%5lld %3d is thinking\n", current_time, philo->name);
	else if (action == DIED)
		printf("%5lld %3d died\n", current_time, philo->name);
	pthread_mutex_unlock(philo->args->writing);
}

void	*philosopher_monitor(void *ptr)
{
	int			i;
	int			number_of_philos;
	long long	current_time;
	long long	time_to_die;
	t_philo		*philos;

	while (1)
	{
		philos = (t_philo *)ptr;
		number_of_philos = philos[0].args->number_of_philos;
		time_to_die = philos[0].args->time_to_die;
		i = -1;
		while (++i < number_of_philos)
		{
			current_time = timenow(philos[0].args->firststamp);
			if ((current_time - philos[i].lastsupper) > time_to_die)
			{
				print_action(&philos[i], DIED);
				philos[i].args->signal = 1;
				pthread_mutex_lock(philos[i].args->writing);
				pthread_mutex_unlock(philos[i].args->writing);
				return (NULL);
			}
		}
	}
	return (NULL);
}
