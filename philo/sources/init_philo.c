/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:53:17 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 07:38:43 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_args(int argc, char **argv, t_args *args)
{
	if (argc == 5 || argc == 6)
	{
		args->number_of_philos = ft_atoi(argv[1]);
		args->time_to_die = ft_atoi(argv[2]);
		args->time_to_eat = ft_atoi(argv[3]);
		args->time_to_sleep = ft_atoi(argv[4]);
		args->times_must_eat = -1;
		if (argc == 6)
			args->times_must_eat = ft_atoi(argv[5]);
		return ;
	}
	else if (argc > 6)
		printf("Too many args!\n");
	else
		printf("Too few args!\n");
	exit (EXIT_FAILURE);
}

void	init_philo(pthread_mutex_t **forks, t_philo **philos)
{
	*forks = NULL;
	*philos = NULL;
}

void	init_forks(int n, t_mutex **forks, t_philo **philos)
{
	int	i;

	*forks = (t_mutex *)malloc(sizeof(t_mutex) * n);
	if (forks == NULL)
	{
		printf("Failed to alloc forks!\n");
		exit_philo (n, *forks, *philos, EXIT_FAILURE);
	}
	i = -1;
	while (++i < n)
		pthread_mutex_init(&(*forks)[i], NULL);
}

void	init_philosophers(int n, t_mutex **forks, t_philo **philos)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * n);
	if (*philos == NULL)
	{
		printf("Failed to alloc philosophers!\n");
		exit_philo (n, *forks, *philos, EXIT_FAILURE);
	}
	i = -1;
	while (++i < (n - 1))
	{
		(*philos)[i].fork_left = forks[i];
		(*philos)[i].fork_right = forks[(i + 1) % n];
		(*philos)[i].name = i + 1;
	}
	(*philos)[i].fork_left = forks[(i + 1) % n];
	(*philos)[i].fork_right = forks[i];
	(*philos)[i].name = i + 1;
}
