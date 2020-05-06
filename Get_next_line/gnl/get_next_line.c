/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:25:08 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/05/06 00:23:38 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **s)
{
	if (*s != NULL || s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

int		ft_creatline(char **s, char **line)
{
	int		n;
	char	*aux;

	n = ft_findchar(*s, '\n');
	if (n < 0)
		n = ft_strlen(*s);
	*line = ft_substr(*s, 0, n);
	aux = ft_substr(*s, n + 1, ft_strlen(*s) - n);
	ft_strdel(s);
	*s = aux;
	aux = NULL;
	return (1);
}

int		gnl_core(int fd, char *buff, char **s, char **line)
{
	int		ret;
	char	*tmp;

	while (ft_findchar(*s, '\n') < 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strjoin(*s, buff);
			ft_strdel(s);
			*s = tmp;
		}
		else if (ret == 0)
		{
			ft_creatline(s, line);
			ft_strdel(s);
			return (0);
		}
		else
			return (-1);
	}
	ft_creatline(s, line);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[FOPEN_MAX];
	char		*buff;
	int			aux;

	if ((fd < 0 || fd >= FOPEN_MAX) || line == NULL
		|| BUFFER_SIZE < 1 || (read(fd, NULL, 0))
		|| !(buff = ft_calloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!str[fd] && !(str[fd] = ft_calloc(1)))
		return (-1);
	aux = gnl_core(fd, buff, &str[fd], line);
	ft_strdel(&buff);
	return (aux);
}
