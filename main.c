/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//all_ate == n_philo = finish eating
//only increment all_ate if n_eat > 0
int	ft_valid(t_var *v, int argc)
{
	if (v->n_philo < 1 || v->n_philo > 200)
		return (ft_error("wrong number of philosophers"));
	if (v->t_die < 60)
		return (ft_error("wrong time to die"));
	if (v->t_eat < 60)
		return (ft_error("wrong time to eat"));
	if (v->t_sleep < 60)
		return (ft_error("wrong time to sleep"));
	if (argc == 6 && v->n_eat < 1)
		return (ft_error("wrong number of meals"));
	return (1);
}

//fill this properly later.
int	ft_onlydigits(char *param)
{
	if (!param)
		return (0);
	return (1);
}

int	ft_onlydigits_(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (ft_error("Wrong amount of arguments"));
	while (i++, i < argc)
	{
		if (!ft_onlydigits(argv[i]))
			return (ft_error("params must not have letters"));
	}
	return (1);
}

int	ft_fill(t_var *v, int argc, char **argv)
{
	if (!ft_onlydigits_(argc, argv))
		return (0);
	v->n_philo = ft_atoi(argv[1]);
	v->t_die = ft_atoi(argv[2]);
	v->t_eat = ft_atoi(argv[3]);
	v->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		v->n_eat = ft_atoi(argv[5]);
	else
		v->n_eat = -1;
	if (!ft_valid(v, argc))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_var	v;

	if (argc != 5 && argc != 6)
		return (ft_error("Wrong amount of arguments"));
	if (ft_fill(&v, argc, argv))
	{
		if (ft_init(&v))
		{
			ft_start(&v);
			ft_finish(&v);
		}
	}
	return (0);
}
