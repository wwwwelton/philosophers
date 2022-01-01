/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:46:42 by wleite            #+#    #+#             */
/*   Updated: 2021/12/31 21:57:18 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_mutex	*forks;
	t_philo	*philos;

	init_args(argc, argv, &data);
	init_data(&data, &forks, &philos);
	init_forks(data.number_of_philos, &data, &forks, &philos);
	init_philos(data.number_of_philos, &data, &forks, &philos);
	start_philosophers(data.number_of_philos, philos);
	deinit_philo(data.number_of_philos, &data, forks, philos);
	return (0);
}
