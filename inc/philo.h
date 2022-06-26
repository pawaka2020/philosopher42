/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramli <riramli@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:00:00 by riramli           #+#    #+#             */
/*   Updated: 2022/06/09 00:00:00 by riramli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

//philosopher
typedef struct s_philo
{
	struct s_var	*v;
	int				id;
	int				n_ate;
	int				left;
	int				right;
	int				lefthand;
	int				righthand;
	long long		t_lastmeal;
}	t_philo;

//required variables for the program to run
typedef struct s_var
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	int				all_ate;
	int				die;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*forks;
	pthread_t		*thr;
	t_philo			*philo;
	long long		start;
}	t_var;

int					write_error(char *str);
int					ft_atoi(const char *str);
int					ft_error(char *str);
int					ft_init(t_var *v);
void				ft_finish(t_var *v);
void				ft_start(t_var *v);
void				*ft_routine(void *info);
void				*ft_monitor(void *info);
long				ft_gettime(void);
void				*ft_pstatus(t_philo *p, char *s);
void				ft_pickforks(t_philo *p);
void				ft_usleep(int n, t_var *v);

#endif
