/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/30 22:19:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	*go_eat_alone(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_action(philo, TOOK_A_FORK);
	pthread_mutex_unlock(philo->fork_right);
	return (NULL);
}

static void	go_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(philo->fork_left);
	if (philo->data->dinner_is_over)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	print_action(philo, TOOK_A_FORK);
	print_action(philo, TOOK_A_FORK);
	print_action(philo, EATING);
	philo->lastsupper = timenow(philo->data->firststamp);
	msleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	philo->meals++;
}

static void	go_sleep(t_philo *philo)
{
	print_action(philo, SLEEPING);
	msleep(philo->data->time_to_sleep);
}

static void	go_think(t_philo *philo)
{
	print_action(philo, THINKING);
	usleep(100);
}

void	*actions(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->name % 2)
		msleep(5);
	if (philo->data->alone)
		return (go_eat_alone(philo));
	while (!philo->data->dinner_is_over)
	{
		go_eat(philo);
		if (philo->meals == philo->data->times_must_eat)
			return (NULL);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}
