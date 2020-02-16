# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_forrest.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 18:02:36 by jaqrodri          #+#    #+#              #
#    Updated: 2020/02/16 18:12:26 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for arg in ${@}
do
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=${arg} get_next_line.c get_next_line_utils.c get_next_line.h
	./a.out
done