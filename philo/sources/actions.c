/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/28 03:37:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	get_a_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (philo->data->signal)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	print_action(philo, TOOK_A_FORK);
	return (1);
}

static int	go_eat(t_philo *philo)
{
	if (philo->data->alone)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (0);
	}
	pthread_mutex_lock(philo->fork_right);
	if (philo->data->signal)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (0);
	}
	print_action(philo, TOOK_A_FORK);
	print_action(philo, EATING);
	philo->meals++;
	philo->lastsupper = timenow(philo->data->firststamp);
	msleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (1);
}

static int	go_sleep(t_philo *philo)
{
	if (philo->data->signal)
		return (0);
	print_action(philo, SLEEPING);
	msleep(philo->data->time_to_sleep);
	return (1);
}

static int	go_think(t_philo *philo)
{
	if (philo->data->signal)
		return (0);
	print_action(philo, THINKING);
	return (1);
}

void	*actions(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (!get_a_fork(philo))
			return (NULL);
		if (!go_eat(philo))
			return (NULL);
		if (philo->meals == philo->data->times_must_eat)
			return (NULL);
		if (!go_sleep(philo))
			return (NULL);
		if (!go_think(philo))
			return (NULL);
	}
	return (NULL);
}
