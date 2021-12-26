/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 09:28:01 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*actions(void *ptr)
{
	int	meals;
	t_philo	*philos;

	meals = 0;
	philos = (t_philo *)ptr;
	while (1)
	{
		printf("%d %d is thinking\n", 20, philos->name);
		usleep(2000000);
		pthread_mutex_lock(philos->fork_left);
		printf("%d %d has taken a fork\n", 20, philos->name);
		pthread_mutex_lock(philos->fork_right);
		printf("%d %d is eating\n", philos->args->time_to_eat, philos->name);
		meals++;
		usleep(philos->args->time_to_eat);
		pthread_mutex_unlock(philos->fork_left);
		pthread_mutex_unlock(philos->fork_right);
		printf("%d %d is sleeping\n", philos->args->time_to_sleep, philos->name);
		usleep(philos->args->time_to_sleep);
	}
	return (NULL);
}
