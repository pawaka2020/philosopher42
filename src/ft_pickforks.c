/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pickforks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_pickforksodd(t_philo *p, int die)
{
	if (die != 1)
	{
		if (!pthread_mutex_lock(&p->v->forks[p->left]))
		{
			p->righthand = 1;
			ft_pstatus(p, "has taken a fork");
		}
		if (!pthread_mutex_lock(&p->v->forks[p->right]) && p->righthand)
		{
			p->lefthand = 1;
			ft_pstatus(p, "has taken a fork");
		}
	}
}

void	ft_pickforkseven(t_philo *p, int die)
{
	if (die != 1)
	{
		if (!pthread_mutex_lock(&p->v->forks[p->right]))
		{
			p->lefthand = 1;
			ft_pstatus(p, "has taken a fork");
		}
		if (!pthread_mutex_lock(&p->v->forks[p->left]) && p->lefthand)
		{
			p->righthand = 1;
			ft_pstatus(p, "has taken a fork");
		}
	}
}

void	ft_pickforks(t_philo *p)
{
	int	die;

	die = p->v->die;
	if (p->id % 2 != 0)
		ft_pickforksodd(p, die);
	else
		ft_pickforkseven(p, die);
}
