/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/27 17:00:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	go_eat(t_philo *philos)
{
	pthread_mutex_lock(philos->fork_left);
	printf("%3lli %3d has taken a fork\n", timenow(philos->args->firststamp), philos->name);
	pthread_mutex_lock(philos->fork_right);
	printf("%3lli %3d has taken a fork\n", timenow(philos->args->firststamp), philos->name);
	printf("%3lli %3d is eating\n", timenow(philos->args->firststamp), philos->name);
	sleep_ms(philos->args->time_to_eat);
	pthread_mutex_unlock(philos->fork_left);
	pthread_mutex_unlock(philos->fork_right);
	philos->meals++;
}

static void	go_sleep(t_philo *philos)
{
	printf("%3lld %3d is sleeping\n", timenow(philos->args->firststamp), philos->name);
	sleep_ms(philos->args->time_to_sleep);
}

static void	go_think(t_philo *philos)
{
	printf("%3lld %3d is thinking\n", timenow(philos->args->firststamp), philos->name);
}

void	*actions(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
	{
		go_eat(philos);
		go_sleep(philos);
		go_think(philos);
	}
	return (NULL);
}
