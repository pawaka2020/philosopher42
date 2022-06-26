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

void	*ft_pstatus(t_philo *p, char *s)
{
	t_var	*v;

	v = p->v;
	pthread_mutex_lock(&p->v->print_lock);
	if (v->die != 1 && v->all_ate < v->n_philo)
		printf("%ld %d %s\n", ft_gettime(), p->id + 1, s);
	pthread_mutex_unlock(&p->v->print_lock);
}
