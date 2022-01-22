/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:53:17 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 14:55:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_args(int argc, char **argv, t_data *data)
{
	check_args(argc, argv);
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_must_eat = -1;
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
}

void	init_data(t_data *data, pthread_mutex_t **forks, t_philo **philos)
{
	*forks = NULL;
	*philos = NULL;
	if (data->number_of_philos == 1)
		data->alone = 1;
	else
		data->alone = 0;
	data->dinner_is_over = 0;
	data->firststamp = 0;
	data->lock_print = (t_mutex *)malloc(sizeof(t_mutex) * 1);
	data->lock_dinner = (t_mutex *)malloc(sizeof(t_mutex) * 1);
	if (data->lock_print == NULL || data->lock_dinner == NULL)
	{
		printf("Failed to alloc mutex!\n");
		exit_philo (0, data, *forks, *philos);
	}
	pthread_mutex_init(data->lock_print, NULL);
	pthread_mutex_init(data->lock_dinner, NULL);
}

void	init_forks(int n, t_data *data, t_mutex **forks, t_philo **philos)
{
	int	i;

	*forks = (t_mutex *)malloc(sizeof(t_mutex) * n);
	if (*forks == NULL)
	{
		printf("Failed to alloc forks!\n");
		exit_philo (n, data, *forks, *philos);
	}
	i = -1;
	while (++i < n)
		pthread_mutex_init(&(*forks)[i], NULL);
}

void	init_philos(int n, t_data *data, t_mutex **forks, t_philo **philos)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * n);
	if (*philos == NULL)
	{
		printf("Failed to alloc philosophers!\n");
		exit_philo (n, data, *forks, *philos);
	}
	i = -1;
	while (++i < n)
	{
		(*philos)[i].fork_right = &(*forks)[i];
		(*philos)[i].fork_left = &(*forks)[i + 1];
		(*philos)[i].lock_supper = (t_mutex *)malloc(sizeof(t_mutex) * 1);
		(*philos)[i].lock_meals = (t_mutex *)malloc(sizeof(t_mutex) * 1);
		(*philos)[i].name = i + 1;
		(*philos)[i].meals = 0;
		(*philos)[i].lastsupper = 0;
		(*philos)[i].data = data;
		pthread_mutex_init((*philos)[i].lock_supper, NULL);
		pthread_mutex_init((*philos)[i].lock_meals, NULL);
	}
	(*philos)[--i].fork_left = &(*forks)[0];
}
