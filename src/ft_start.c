/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_one(t_var *v)
{
	long	time;

	time = ft_gettime();
	printf("%ld 1 is thinking\n", time);
	usleep(v->t_die * 1000);
	printf("%ld 1 died\n", time + v->t_die);
}

void	ft_start(t_var *v)
{
	int	i;

	i = -1;
	if (v->n_philo == 1)
		ft_philo_one(v);
	else
	{
		v->start = ft_gettime();
		while (i++, i < v->n_philo)
		{
			v->philo[i].t_lastmeal = v->start;
			pthread_create(&v->thr[i], 0, &ft_routine, &v->philo[i]);
		}
		ft_monitor(v);
		i = -1;
		while (++i < v->n_philo)
			pthread_join(v->thr[i], 0);
	}
}
