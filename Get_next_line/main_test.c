/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:23:28 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/19 06:30:52 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int	fd;
	// int a;
	char *line[OPEN_MAX];

(void)argv;	
	if (argc == 1)
		fd = 0;
	else if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		
		if(fd == -1)
			return(1);
		while(get_next_line(fd, (char **)&line) == 1)
		{
			// ft_putnbr(a);
			//printf("%s\n", *line);
			// ft_putstr("|\n");
			
		
		}
	}
	else 
		return (2);
	if (argc == 2)
		close(fd);	
}