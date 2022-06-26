# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riramli <riramli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 11:23:18 by riramli           #+#    #+#              #
#    Updated: 2022/06/09 16:42:21 by riramli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= philo
FLAG		= -Wall -Wextra -Werror -pthread
CHECK		= -g -fsanitize=thread

all:	$(NAME)

$(NAME):
	gcc -c -Iinc src/*.c
	gcc $(FLAG) $(CHECK) main.c -Iinc *.o -o $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm $(NAME)

re:		fclean all

# remember to make re first if you changed any code.
# from evaluation page. Philo should not eat and should die
t1:
	./$(NAME) 1 800 200 200
# no die
t2:
	./$(NAME) 5 800 200 200
# no die. 'x is eating' should appear 7 times.
t3:
	./$(NAME) 5 800 200 200 7
# no die. 
t4:
	./$(NAME) 4 410 200 200
# die while waiting to eat. For instance 1 will die at 300 because 4 is still eating and will only release fork at 400.
t5:
	./$(NAME) 4 310 200 100
# last but not least, test with small numbers. A philo should die.
t6:
	./$(NAME) 4 119 61 61

.PHONY: all run clean
