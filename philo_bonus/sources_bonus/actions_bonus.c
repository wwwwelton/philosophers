/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 12:29:40 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	go_eat_alone(t_philo *philo)
{
	sem_wait(philo->fork_right);
	print_action(philo, TOOK_A_FORK);
	dsleep(philo->data->time_to_die, philo);
}

static void	go_eat(t_philo *philo)
{
	sem_wait(philo->fork_right);
	sem_wait(philo->fork_left);
	print_action(philo, TOOK_A_FORK);
	print_action(philo, TOOK_A_FORK);
	print_action(philo, EATING);
	philo->lastsupper = timenow(philo->data->firststamp);
	dsleep(philo->data->time_to_eat, philo);
	sem_post(philo->fork_right);
	sem_post(philo->fork_left);
	philo->meals++;
}

static void	go_sleep(t_philo *philo)
{
	print_action(philo, SLEEPING);
	dsleep(philo->data->time_to_sleep, philo);
}

static void	go_think(t_philo *philo)
{
	print_action(philo, THINKING);
	usleep(500);
	sem_try_wait(philo);
}

int	actions(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->name % 2 == 0)
		msleep(5);
	if (philo->data->alone)
		go_eat_alone(philo);
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
