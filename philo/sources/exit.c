/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/28 03:37:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	deinit_philo(int n, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(philos[0].data->writing);
	free(philos[0].data->writing);
	free(forks);
	free(philos);
}

void	exit_philo(int n, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(philos[0].data->writing);
	free(philos[0].data->writing);
	free(forks);
	free(philos);
	exit(EXIT_FAILURE);
}
