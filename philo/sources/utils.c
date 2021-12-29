/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/29 20:25:18 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

	pthread_mutex_lock(philo->data->writing);
	current_time = timenow(philo->data->firststamp);
	if (action == TOOK_A_FORK && !philo->data->dinner_is_over)
		printf("%5ld %3d has taken a fork\n", current_time, philo->name);
	else if (action == EATING && !philo->data->dinner_is_over)
		printf("%5ld %3d is eating\n", current_time, philo->name);
	else if (action == SLEEPING && !philo->data->dinner_is_over)
		printf("%5ld %3d is sleeping\n", current_time, philo->name);
	else if (action == THINKING && !philo->data->dinner_is_over)
		printf("%5ld %3d is thinking\n", current_time, philo->name);
	else if (action == DIED)
		printf("%5ld %3d died\n", current_time, philo->name);
	pthread_mutex_unlock(philo->data->writing);
}
