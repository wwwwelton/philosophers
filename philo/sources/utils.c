/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/27 16:56:28 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleep_ms(int time)
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
		sleep_ms(10);
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
