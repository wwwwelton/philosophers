/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 17:08:34 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	deinit_philo(int n, t_data *data, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n && forks)
		pthread_mutex_destroy(&forks[i]);
	i = -1;
	while (++i < n && philos)
	{
		if (philos[i].lock_supper)
			pthread_mutex_destroy(philos[i].lock_supper);
		if (philos[i].lock_meals)
			pthread_mutex_destroy(philos[i].lock_meals);
		free(philos[i].lock_supper);
		free(philos[i].lock_meals);
	}
	if (data->lock_print)
		pthread_mutex_destroy(data->lock_print);
	if (data->lock_dinner)
		pthread_mutex_destroy(data->lock_dinner);
	free(data->lock_print);
	free(data->lock_dinner);
	free(forks);
	free(philos);
}

void	exit_philo(int n, t_data *data, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n && forks)
		pthread_mutex_destroy(&forks[i]);
	i = -1;
	while (++i < n && philos)
	{
		if (philos[i].lock_supper)
			pthread_mutex_destroy(philos[i].lock_supper);
		if (philos[i].lock_meals)
			pthread_mutex_destroy(philos[i].lock_meals);
		free(philos[i].lock_supper);
		free(philos[i].lock_meals);
	}
	if (data->lock_print)
		pthread_mutex_destroy(data->lock_print);
	if (data->lock_dinner)
		pthread_mutex_destroy(data->lock_dinner);
	free(data->lock_print);
	free(data->lock_dinner);
	free(forks);
	free(philos);
	exit(EXIT_FAILURE);
}
