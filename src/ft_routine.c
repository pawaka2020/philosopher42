/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *p)
{
	t_var	*v;

	v = p->v;
	ft_pickforks(p);
	ft_pstatus(p, "is eating");
	p->t_lastmeal = ft_gettime() + v->t_die;
	if (v->n_eat != 0)
	{
		p->n_ate++;
		if (p->n_ate == v->n_eat)
			v->all_ate++;
	}
	ft_usleep(p->v->t_eat, p->v);
	pthread_mutex_unlock(&(v->forks[p->left]));
	pthread_mutex_unlock(&(v->forks[p->right]));
	p->lefthand = 0;
	p->righthand = 0;
}

void	*ft_routine(void *info)
{
	t_philo			*p;

	p = (t_philo *)info;
	ft_pstatus(p, "is thinking");
	if (p->id % 2 == 1)
		ft_usleep(60, p->v);
	while (p->v->die != 1)
	{
		ft_eat(p);
		if (p->n_ate == p->v->n_eat)
			return (0);
		ft_pstatus(p, "is sleeping");
		ft_usleep(p->v->t_sleep, p->v);
		ft_pstatus(p, "is thinking");
	}
	return (0);
}
