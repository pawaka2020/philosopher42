/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_declaredeath(t_var *v, long time, int i )
{
	v->die = 1;
	pthread_mutex_lock(&v->print_lock);
	printf("%ld %d died\n", time, v->philo[i].id + 1);
	pthread_mutex_unlock(&v->print_lock);
}

void	*ft_monitor(void *info)
{
	int			i;
	long		time;
	t_var		*v;

	v = (t_var *)info;
	while (v->die != 1)
	{
		if (v->all_ate == v->n_philo)
			return (0);
		if (v->die != -1)
		{
			i = -1;
			time = ft_gettime();
			while (i++, i < v->n_philo)
			{
				if (time > v->philo[i].t_lastmeal \
				&& v->philo[i].t_lastmeal != v->start)
				{
					ft_declaredeath(v, time, i);
					return (0);
				}
			}
		}
	}
	return (0);
}
