/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2022/01/22 17:20:14 by wleite           ###   ########.fr       */
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

int	dinner_is_over(t_philo *philo)
{
	int	dinner_is_over;

	pthread_mutex_lock(philo->data->lock_dinner);
	dinner_is_over = 0;
	if (philo->data->dinner_is_over)
		dinner_is_over = philo->data->dinner_is_over;
	pthread_mutex_unlock(philo->data->lock_dinner);
	return (dinner_is_over);
}

void	finish_dinner(t_philo *philo)
{
	pthread_mutex_lock(philo->data->lock_dinner);
	philo->data->dinner_is_over = 1;
	pthread_mutex_unlock(philo->data->lock_dinner);
}

void	print_action(t_philo *philo, int action)
{
	long	current_time;

	pthread_mutex_lock(philo->data->lock_print);
	current_time = timenow(philo->data->firststamp);
	if (action == TOOK_A_FORK && !dinner_is_over(philo))
		printf("%5ld %3d has taken a fork\n", current_time, philo->name);
	else if (action == EATING && !dinner_is_over(philo))
		printf("%5ld %3d is eating\n", current_time, philo->name);
	else if (action == SLEEPING && !dinner_is_over(philo))
		printf("%5ld %3d is sleeping\n", current_time, philo->name);
	else if (action == THINKING && !dinner_is_over(philo))
		printf("%5ld %3d is thinking\n", current_time, philo->name);
	else if (action == DIED)
		printf("%5ld %3d died\n", current_time, philo->name);
	pthread_mutex_unlock(philo->data->lock_print);
}
