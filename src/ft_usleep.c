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

void	ft_usleep(int n, t_var *v)
{
	long long	begin;
	long long	current;

	begin = ft_gettime();
	while (v->die != 1 && v->all_ate < v->n_philo)
	{
		current = ft_gettime();
		if (((current - begin)) >= (long)n)
			break ;
		usleep(100);
	}
}
