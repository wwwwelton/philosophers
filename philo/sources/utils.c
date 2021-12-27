/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/27 18:37:13 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	msleep(int time)
{
	usleep(time * 1000);
	return (time * 1000);
}

int	start_philosophers(int n, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		pthread_create(&philos[i].thread, NULL, &actions, &philos[i]);
		msleep(5);
	}
	i = -1;
	while (++i < n)
		pthread_join(philos[i].thread, NULL);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	timenow(long long firststamp)
{
	return (timestamp() - firststamp);
}

void	print_action(t_philo *philo, int action)
{
	long long	current_time;

	current_time = timenow(philo->args->firststamp);
	if (action == TOOK_A_FORK)
		printf("%5lld %3d has taken a fork\n", current_time, philo->name);
	else if (action == EATING)
		printf("%5lld %3d is eating\n", current_time, philo->name);
	else if (action == SLEEPING)
		printf("%5lld %3d is sleeping\n", current_time, philo->name);
	else if (action == THINKING)
		printf("%5lld %3d is thinking\n", current_time, philo->name);
}
