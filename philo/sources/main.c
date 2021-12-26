/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:46:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 03:47:52 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//n_of_philos || time_to_die || time_to_eat || time_to_sleep || times_must_eat

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	t_args			args;
	t_philosopher	*philos;

	init_args(argc, argv, &args);
	init_philo(&forks, &philos);
	init_forks(args.number_of_philos, &forks, &philos);
	init_philosophers(args.number_of_philos, &forks, &philos);
	deinit_philo(args.number_of_philos, forks, philos);
	// print_args(args);
	return (0);
}
