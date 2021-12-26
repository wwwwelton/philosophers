/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:56:08 by wleite            #+#    #+#             */
/*   Updated: 2021/12/26 08:04:19 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*actions(void *ptr)
{
	t_philo	*philos;

	(void)philos;
	philos = (t_philo *)ptr;
	printf("Thread created for philo %ld\n", pthread_self());
	usleep(10000);
	return (NULL);
}
