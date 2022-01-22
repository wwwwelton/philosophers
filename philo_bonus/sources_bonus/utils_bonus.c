/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 13:39:21 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j])
				|| ft_atol(argv[i]) > 2147483647
				|| ft_atol(argv[i]) == 0)
			{
				printf("Error!\n");
				exit (EXIT_FAILURE);
			}
		}
	}
	if (argc > 6)
		printf("Too many args!\n");
	else if (argc < 5)
		printf("Too few args!\n");
	else
		return ;
	exit (EXIT_FAILURE);
}

void	print_action(t_philo *philo, int action)
{
	long	current_time;

	sem_wait(philo->data->lock_print);
	current_time = timenow(philo->data->firststamp);
	if (action == TOOK_A_FORK)
		printf("%5ld %3d has taken a fork\n", current_time, philo->name);
	else if (action == EATING)
		printf("%5ld %3d is eating\n", current_time, philo->name);
	else if (action == SLEEPING)
		printf("%5ld %3d is sleeping\n", current_time, philo->name);
	else if (action == THINKING)
		printf("%5ld %3d is thinking\n", current_time, philo->name);
	else if (action == DIED)
		printf("%5ld %3d died\n", current_time, philo->name);
	if (action != DIED)
		sem_post(philo->data->lock_print);
}

void	sem_try_wait(t_philo *philo)
{
	long	current_time;

	while (*(long *)philo->forks < 2)
	{
		current_time = timenow(philo->data->firststamp);
		if ((current_time - philo->lastsupper) > philo->data->time_to_die)
		{
			print_action(philo, DIED);
			exit_philo(philo->data, philo->forks, philo->philos, 1);
		}
		usleep(10);
	}
}
