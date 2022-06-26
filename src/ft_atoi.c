/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_checklimits(long res, int sign)
{
	if ((sign == 1) && (res >= 0x7FFFFFFF))
		return (-1);
	else if ((sign == -1) && (res >= 0x80000000))
		return (0);
	else
		return (res * sign);
}

/*
Parameters entered will always be in string form.
Thus we need to use atoi to convert the string values to usable integers.
We are not allowed to use atoi so we make our own _atoi instead. 
*/
int	ft_atoi(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (s && *s && *s < 33)
		s++;
	if (s && *s == '-')
		sign = -1;
	while (s && *s && (*s == '-' || *s == '+'))
		s++;
	while (s && *s && *s >= '0' && *s <= '9')
	{
		res = (res * 10) + (*s - '0');
		s++;
	}
	res = _checklimits(res, sign);
	return (res);
}
