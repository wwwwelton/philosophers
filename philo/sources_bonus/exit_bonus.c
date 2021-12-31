/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/30 22:19:26 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	deinit_philo(int n, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(philos->data->writing);
	free(philos->data->writing);
	free(forks);
	free(philos);
}

void	exit_philo(int n, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(philos->data->writing);
	free(philos->data->writing);
	free(forks);
	free(philos);
	exit(EXIT_FAILURE);
}
