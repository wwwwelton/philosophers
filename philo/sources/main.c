/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:46:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/28 03:34:36 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//n_of_philos || time_to_die || time_to_eat || time_to_sleep || times_must_eat

int	main(int argc, char **argv)
{
	t_mutex	*forks;
	t_data	data;
	t_philo	*philos;

	init_args(argc, argv, &data);
	init_data(&data, &forks, &philos);
	init_forks(data.number_of_philos, &forks, &philos);
	init_philos(data.number_of_philos, &data, &forks, &philos);
	start_philosophers(data.number_of_philos, philos);
	deinit_philo(data.number_of_philos, forks, philos);
	return (0);
}
