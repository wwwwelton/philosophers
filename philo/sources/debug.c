/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 00:21:38 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 00:22:35 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_args(t_args args)
{
	printf("n_of_philos %d\n", args.number_of_philos);
	printf("time_to_die %d\n", args.time_to_die);
	printf("time_to_eat %d\n", args.time_to_eat);
	printf("time_to_sleep %d\n", args.time_to_sleep);
	printf("times_must_eat %d\n", args.times_must_eat);
}
