/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 20:15:56 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	process_create(pid_t *process, int (*f)(void *), t_philo *philo)
{
	int	exit_code;

	exit_code = 0;
	*process = fork();
	if (*process == 0)
	{
		exit_code = f(philo);
		exit_philo(philo->data, philo->forks, philo->philos, exit_code);
	}
	return (exit_code);
}

int	process_join(t_philo *philos)
{
	int	i;
	int	exit_code;

	exit_code = 0;
	i = -1;
	while (++i < philos->data->number_of_philos && exit_code == 0)
	{
		waitpid(-1, &exit_code, 0);
		exit_code = WEXITSTATUS(exit_code);
	}
	if (exit_code)
	{
		i = -1;
		while (++i < philos->data->number_of_philos)
			kill(philos[i].process, SIGKILL);
	}
	return (exit_code);
}

int	start_philosophers(int n, t_philo *philos)
{
	int	i;

	i = -1;
	philos->data->firststamp = timestamp();
	while (++i < n)
		process_create(&philos[i].process, &actions, &philos[i]);
	process_join(philos);
	return (0);
}
