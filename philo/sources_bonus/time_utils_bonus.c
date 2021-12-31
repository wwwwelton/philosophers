/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:25:19 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 07:00:53 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	msleep(int time_in_ms)
{
	long	start_time;

	start_time = timestamp();
	while ((timestamp() - start_time) < (long)time_in_ms)
		usleep(10);
}

int	msleep_of_death(int time_in_ms, t_philo *philo)
{
	long	current_time;
	long	start_time;

	start_time = timestamp();
	while ((timestamp() - start_time) < (long)time_in_ms)
	{
		current_time = timenow(philo->data->firststamp);
		if ((current_time - philo->lastsupper) > philo->data->time_to_die)
			return (1);
		usleep(10);
	}
	return (0);
}

long	timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	timenow(long firststamp)
{
	return (timestamp() - firststamp);
}
