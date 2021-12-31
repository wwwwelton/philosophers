/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 03:48:05 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	deinit_philo(t_data *data, sem_t *forks, t_philo *philos)
{
	sem_close(forks);
	sem_unlink("/forks");
	sem_close(data->writing);
	sem_unlink("/writing");
	free(philos);
}

void	exit_philo(t_data *data, sem_t *forks, t_philo *philos, int exit_code)
{
	sem_close(forks);
	sem_unlink("/forks");
	sem_close(data->writing);
	sem_unlink("/writing");
	free(philos);
	exit(exit_code);
}
