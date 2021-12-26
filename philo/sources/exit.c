/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 07:42:44 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	deinit_philo(int n, t_mutex *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
	free(philos);
}

void	exit_philo(int n, t_mutex *forks, t_philo *philos, int code)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
	free(philos);
	exit(code);
}
