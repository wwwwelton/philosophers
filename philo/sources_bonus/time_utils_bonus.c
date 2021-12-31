/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:25:19 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 15:32:17 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	dsleep(int time_in_ms, t_philo *philo)
{
	long	current_time;
	long	start_time;

	start_time = timestamp();
	while ((timestamp() - start_time) < (long)time_in_ms)
	{
		current_time = timenow(philo->data->firststamp);
		if ((current_time - philo->lastsupper) > philo->data->time_to_die)
		{
			print_action(philo, DIED);
			exit_philo(philo->data, philo->forks, philo->philos, 1);
		}
		usleep(10);
	}
	if (philo->data->alone)
	{
		print_action(philo, DIED);
		exit_philo(philo->data, philo->forks, philo->philos, 1);
	}
}

void	msleep(int time_in_ms)
{
	long	start_time;

	start_time = timestamp();
	while ((timestamp() - start_time) < (long)time_in_ms)
		usleep(10);
}

void	tsleep(t_philo *philo)
{
	long		current_time;

	while (philo->forks->__align < 2)
	{
		current_time = timenow(philo->data->firststamp);
		if ((current_time - philo->lastsupper) > philo->data->time_to_die)
		{
			print_action(philo, DIED);
			exit_philo(philo->data, philo->forks, philo->philos, 1);
		}
		usleep(10);
	}
}
