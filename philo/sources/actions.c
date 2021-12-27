/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/27 19:16:04 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	go_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_action(philo, TOOK_A_FORK);
	if (pthread_mutex_lock(philo->fork_right) == EOWNERDEAD)
	{
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	print_action(philo, TOOK_A_FORK);
	print_action(philo, EATING);
	philo->meals++;
	philo->lastsupper = timenow(philo->args->firststamp);
	msleep(philo->args->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

static void	go_sleep(t_philo *philo)
{
	print_action(philo, SLEEPING);
	msleep(philo->args->time_to_sleep);
}

static void	go_think(t_philo *philo)
{
	print_action(philo, THINKING);
}

void	*actions(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		go_eat(philo);
		if (philo->meals == philo->args->times_must_eat)
			return (NULL);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}
