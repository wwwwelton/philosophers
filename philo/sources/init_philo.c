/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:53:17 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 03:57:34 by wleite           ###   ########.fr       */
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
		return ;
	}
	else if (argc > 6)
		printf("Too many args!\n");
	else
		printf("Too few args!\n");
	exit (EXIT_FAILURE);
}

void	init_philosophers(int number_of_philos,
		pthread_mutex_t **forks, t_philosopher **philos)
{
	int	i;

	*philos = (t_philosopher *)malloc(sizeof(t_philosopher) * number_of_philos);
	if (philos == NULL)
	{
		printf("Failed to alloc philosophers!\n");
		exit_philo (number_of_philos, *forks, *philos, EXIT_FAILURE);
	}
	i = -1;
	while (++i < (number_of_philos - 1))
	{
		philos[i]->fork_left = forks[i];
		philos[i]->fork_right = forks[(i + 1) % number_of_philos];
		philos[i]->name = i + 1;
		printf("philo: %d\n", i);
	}
	philos[i]->fork_left = forks[(i + 1) % number_of_philos];
	philos[i]->fork_right = forks[i];
	philos[i]->name = i + 1;
	printf("philo: %d\n", i);
}

void	init_forks(int number_of_philos,
		pthread_mutex_t **forks, t_philosopher **philos)
{
	int	i;

	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (forks == NULL)
	{
		printf("Failed to alloc forks!\n");
		exit_philo (number_of_philos, *forks, *philos, EXIT_FAILURE);
	}
	i = -1;
	while (++i < number_of_philos)
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		printf("fork: %d\n", i);
	}
}
