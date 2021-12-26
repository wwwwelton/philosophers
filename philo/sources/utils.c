/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:03:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 00:18:16 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_args(int argc, char **argv, t_args	*args)
{
	if (argc == 5 || argc == 6)
	{
		args->number_of_philos = ft_atoi(argv[1]);
		args->time_to_die = ft_atoi(argv[2]);
		args->time_to_eat = ft_atoi(argv[3]);
		args->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			args->times_must_eat = ft_atoi(argv[5]);
		return (0);
	}
	else if (argc > 6)
		printf("Too many args!\n");
	else
		printf("Too few args!\n");
	exit (EXIT_FAILURE);
	return (0);
}
