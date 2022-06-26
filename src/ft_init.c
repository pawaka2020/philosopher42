/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//if retur 0 philo can die
//if return -1 philo impossible mathametically to die
int	ft_setdie(t_var *v)
{
	int	n;
	int	d;
	int	e;
	int	s;

	n = v->n_philo;
	d = v->t_die;
	e = v->t_eat;
	s = v->t_sleep;
	if (n % 2 == 1 && d >= (e * 4) && d >= (e + s))
		return (-1);
	else if (n % 2 == 0 && d >= (e * 2) && d >= (e + s))
		return (-1);
	return (0);
}

void	ft_initforks(t_var *v)
{
	int	i;

	i = -1;
	while (i++, i < v->n_philo)
		pthread_mutex_init(&v->forks[i], 0);
}

void	ft_initphilo(t_var *v)
{
	int	i;

	i = -1;
	while (i++, i < v->n_philo)
	{
		v->philo[i].v = v;
		v->philo[i].id = i;
		v->philo[i].n_ate = 0;
		v->philo[i].left = i;
		v->philo[i].right = (i + 1) % v->n_philo;
		v->philo[i].lefthand = 0;
		v->philo[i].righthand = 0;
	}
}

int	ft_init(t_var *v)
{
	v->all_ate = 0;
	v->die = ft_setdie(v);
	pthread_mutex_init(&v->print_lock, 0);
	v->forks = malloc(sizeof(pthread_mutex_t) * v->n_philo);
	v->thr = malloc(sizeof(pthread_t) * v->n_philo);
	v->philo = malloc(sizeof(t_philo) * v->n_philo);
	if (!v->forks || !v->thr || !v->philo)
		return (0);
	ft_initforks(v);
	ft_initphilo(v);
	return (1);
}
