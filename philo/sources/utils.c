/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 03:50:41 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(pthread_mutex_t **forks, t_philosopher **philos)
{
	*forks = NULL;
	*philos = NULL;
}

void	deinit_philo(int number_of_philos,
		pthread_mutex_t *forks, t_philosopher *philos)
{
	int	i;

	printf("number_of_philos %d\n", number_of_philos);
	i = -1;
	while (++i < number_of_philos)
	{
		// pthread_mutex_destroy(&forks[i]);
		// printf("destroy %d\n", i);
		printf("name %d %d\n", i, philos[i].name);
	}
	free(forks);
	free(philos);
}

void	exit_philo(int number_of_philos,
		pthread_mutex_t *forks, t_philosopher *philos, int code)
{
	int	i;

	i = -1;
	while (++i < number_of_philos)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
	free(philos);
	exit(code);
}
