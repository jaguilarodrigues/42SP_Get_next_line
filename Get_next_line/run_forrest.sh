# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_forrest.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 18:02:36 by jaqrodri          #+#    #+#              #
#    Updated: 2020/03/04 16:42:08 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

for arg in ${@}
do
	#gcc -Wall -Wextra -Werror main_test.c get_next_line.h get_next_line_utils.c 
	gcc -Wall -Wextra -Werror -g -D BUFFER_SIZE=${arg} ~/42/Get_next_line/42SP_Get_next_line/Get_next_line/*.c ~/42/Get_next_line/42SP_Get_next_line/Get_next_line/*.h
#./a.out text
#	rm ./a.out
done