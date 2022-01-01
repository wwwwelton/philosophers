/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 22:06:45 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	deinit_philo(int n, t_data *data, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n && forks)
		pthread_mutex_destroy(&forks[i]);
	if (data->writing)
		pthread_mutex_destroy(data->writing);
	free(data->writing);
	free(forks);
	free(philos);
}

void	exit_philo(int n, t_data *data, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n && forks)
		pthread_mutex_destroy(&forks[i]);
	if (data->writing)
		pthread_mutex_destroy(data->writing);
	free(data->writing);
	free(forks);
	free(philos);
	exit(EXIT_FAILURE);
}
