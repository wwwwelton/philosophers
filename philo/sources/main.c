/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:46:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 07:45:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//n_of_philos || time_to_die || time_to_eat || time_to_sleep || times_must_eat

int	main(int argc, char **argv)
{
	t_mutex	*forks;
	t_args	args;
	t_philo	*philos;

	init_args(argc, argv, &args);
	init_data(&forks, &philos);
	init_forks(args.number_of_philos, &forks, &philos);
	init_philosophers(args.number_of_philos, &forks, &philos);
	deinit_philo(args.number_of_philos, forks, philos);
	return (0);
}
