/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:53:17 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 13:39:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	init_data(t_data *data, sem_t **forks, t_philo **philos)
{
	sem_unlink("/lock_print");
	sem_unlink("/forks");
	*forks = NULL;
	*philos = NULL;
	if (data->number_of_philos == 1)
		data->alone = 1;
	else
		data->alone = 0;
	data->firststamp = 0;
	data->lock_print = NULL;
	data->lock_print = sem_open("/lock_print", O_CREAT, 0777, 1);
	if (data->lock_print == NULL)
	{
		printf("Failed to create semaphore!\n");
		exit_philo (data, *forks, *philos, 1);
	}
}

void	init_forks(int n, t_data *data, sem_t **forks, t_philo **philos)
{
	*forks = sem_open("/forks", O_CREAT, 0777, n);
	if (*forks == NULL)
	{
		printf("Failed to create semaphore!\n");
		exit_philo (data, *forks, *philos, 1);
	}
}

void	init_philos(int n, t_data *data, sem_t **forks, t_philo **philos)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * n);
	if (*philos == NULL)
	{
		printf("Failed to alloc philosophers!\n");
		exit_philo (data, *forks, *philos, 1);
	}
	i = -1;
	while (++i < n)
	{
		(*philos)[i].fork_right = *forks;
		(*philos)[i].fork_left = *forks;
		(*philos)[i].name = i + 1;
		(*philos)[i].meals = 0;
		(*philos)[i].lastsupper = 0;
		(*philos)[i].forks = *forks;
		(*philos)[i].data = data;
		(*philos)[i].philos = *philos;
	}
}
