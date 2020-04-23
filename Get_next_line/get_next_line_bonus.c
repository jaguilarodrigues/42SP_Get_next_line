/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 21:08:37 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/04/23 00:05:28 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1)
{
	char	*copstring;
	int		i;

	i = 0;
	copstring = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copstring == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copstring[i] = s1[i];
		i++;
	}
	copstring[i] = '\0';
	return (copstring);
}

int		ft_creatline(char **s, char **line)
{
	int		n;
	char	*aux;

	n = ft_findchar(*s, '\n');
	if (n < 0)
	{
		*line = ft_strdup(*s);
		return (0);
	}
	*line = ft_substr(*s, 0, n);
	aux = ft_substr(*s, n + 1, ft_strlen(*s) - n);
	free(*s);
	*s = aux;
	aux = NULL;
	return (1);
}

int		gnl_core(int fd, char *buff, char **s, char **line)
{
	int	ret;

	while (ft_findchar(*s, '\n') < 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[ret] = '\0';
			*s = ft_strjoin(*s, buff);
		}
		else if (ret == 0)
		{
			ft_creatline(s, line);
			free(*s);
			s = ft_strdup("");
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
		|| !(buff = ft_calloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	if (!str[fd] && !(str[fd] = ft_calloc(1)))
		return (-1);
	aux = gnl_core(fd, buff, &str[fd], line);
	free(buff);
	buff = ft_strdup("");
	return (aux);
}
