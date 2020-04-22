# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_forrest.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 18:02:36 by jaqrodri          #+#    #+#              #
#    Updated: 2020/04/22 00:06:45 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

for arg in ${@}
do
	#gcc -Wall -Wextra -Werror main_test.c get_next_line.h get_next_line_utils.c 
	clang -Wall -Wextra -Werror -g -D BUFFER_SIZE=${arg} ~/Documentos/42/42SP_Get_next_line/Get_next_line/main_test.c ~/Documentos/42/42SP_Get_next_line/Get_next_line/get_next_line.c ~/Documentos/42/42SP_Get_next_line/Get_next_line/get_next_line.h ~/Documentos/42/42SP_Get_next_line/Get_next_line/get_next_line_utils.c
#./a.out text
#	rm ./a.out
done