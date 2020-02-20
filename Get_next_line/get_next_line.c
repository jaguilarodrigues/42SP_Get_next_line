/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:25:08 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/20 11:53:47 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{

	char		*buff;
	int			ret;
	char		*p;
	char		*a;
	static char	*res;
	
	a = malloc(sizeof(char));
	ret = -1;
	p = NULL;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while(p == NULL)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		p = ft_strchr(buff, '\n');
		if (p == NULL)
			a = ft_strjoin(a, buff);
		else
			a = ft_strjoinchr(a, *(p++));
	}
	// while(*p != '\n')
	// {
	// 	ft_strjoinchr(a, *p);
	// 	p++;
	// }
	res = p;
	*line = a;
	
	free(buff);
	if(ret == -1 || ret == 0)
		return (0);
	return (1);
	
}
	