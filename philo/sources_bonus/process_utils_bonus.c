/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 03:46:48 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	process_create(pid_t *process, int (*f)(void *), t_philo *philo)
{
	int	exit_code;

	*process = fork();
	if (*process == 0)
	{
		exit_code = f(philo);
		exit_philo(philo->data, philo->forks, philo->philos, exit_code);
	}
	return (*process);
}

int	process_join(void)
{
	int	exit_code;

	exit_code = 0;
	waitpid(-1, &exit_code, 0);
	if (WIFEXITED(exit_code))
		exit_code = WEXITSTATUS(exit_code);
	return (exit_code);
}
