/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:25:08 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/03/04 16:37:28 by jaqrodri         ###   ########.fr       */
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
	
	a = ft_calloc(1, sizeof(char));
	if (res == NULL)
		res = ft_calloc(1, sizeof(char));
	ret = 1;
	p = NULL;
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while(p == NULL && ret >= 0)
	{
		if(*res != '\0')
		{
			a = ft_strjoin(a, res);
			free(res);
			res = ft_calloc(1, sizeof(char));
		}
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		p = ft_strchr(buff, '\n');
		if (p != NULL)
		{
			*(p++) = '\0';
			res = ft_strjoin(res, p);
		}
			a = ft_strjoin(a, buff);
		if(ret == 0)
			break;
	}
	
	*line = a;
	
	free(buff);
	free(a);
	buff = NULL;
	a = NULL;
	
	if(ret == -1 || ret == 0)
		return (0);
	return (1);
	
}
	