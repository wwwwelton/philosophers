/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 13:39:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	deinit_philo(t_data *data, sem_t *forks, t_philo *philos)
{
	sem_close(forks);
	sem_close(data->lock_print);
	sem_unlink("/forks");
	sem_unlink("/lock_print");
	free(philos);
}

void	exit_philo(t_data *data, sem_t *forks, t_philo *philos, int exit_code)
{
	sem_close(forks);
	sem_close(data->lock_print);
	sem_unlink("/forks");
	sem_unlink("/lock_print");
	free(philos);
	exit(exit_code);
}
