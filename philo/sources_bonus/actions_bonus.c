/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 14:07:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	go_eat_alone(t_philo *philo)
{
	sem_wait(philo->fork_right);
	print_action(philo, TOOK_A_FORK);
	msleep(philo->data->time_to_die);
	print_action(philo, DIED);
	sem_post(philo->fork_right);
	return (1);
}

static void	go_eat(t_philo *philo)
{
	if (dmsleep_of_death(philo))
	{
		print_action(philo, DIED);
		exit_philo(philo->data, philo->forks, philo->philos, 1);
	}
	sem_wait(philo->fork_right);
	sem_wait(philo->fork_left);
	print_action(philo, TOOK_A_FORK);
	print_action(philo, TOOK_A_FORK);
	print_action(philo, EATING);
	philo->lastsupper = timenow(philo->data->firststamp);
	if (msleep_of_death(philo->data->time_to_eat, philo))
	{
		print_action(philo, DIED);
		exit_philo(philo->data, philo->forks, philo->philos, 1);
	}
	sem_post(philo->fork_right);
	sem_post(philo->fork_left);
	philo->meals++;
}

static void	go_sleep(t_philo *philo)
{
	print_action(philo, SLEEPING);
	if (msleep_of_death(philo->data->time_to_sleep, philo))
	{
		print_action(philo, DIED);
		exit_philo(philo->data, philo->forks, philo->philos, 1);
	}
}

static void	go_think(t_philo *philo)
{
	print_action(philo, THINKING);
	usleep(100);
}

int	actions(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->name % 2 == 0)
		msleep(5);
	if (philo->data->alone)
		return (go_eat_alone(philo));
	while (1)
	{
		go_eat(philo);
		if (philo->meals == philo->data->times_must_eat)
			exit_philo(philo->data, philo->forks, philo->philos, 0);
		go_sleep(philo);
		go_think(philo);
	}
	return (0);
}
