/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 15:42:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_meals(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(philo->lock_meals);
	meals = philo->meals;
	pthread_mutex_unlock(philo->lock_meals);
	return (meals);
}

void	set_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meals);
	philo->meals++;
	pthread_mutex_unlock(philo->lock_meals);
}

int	get_lastsupper(t_philo *philo)
{
	long	lastsupper;

	pthread_mutex_lock(philo->lock_supper);
	lastsupper = philo->lastsupper;
	pthread_mutex_unlock(philo->lock_supper);
	return (lastsupper);
}

void	set_lastsupper(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_supper);
	philo->lastsupper = timenow(philo->data->firststamp);
	pthread_mutex_unlock(philo->lock_supper);
}
