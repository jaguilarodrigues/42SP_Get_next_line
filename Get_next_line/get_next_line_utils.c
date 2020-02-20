/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:17:04 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/17 21:28:22 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while(*s != '\0')
	{
		ft_putchr(*s);
		s++;
	}
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchr('\n');
}

void	ft_putfile(int fd)
{
	int		ret;
	char	buf[4097];

	while((ret = read(fd, buf, 4096)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ft_putchr('\n');
	}
}

void	ft_putnbr(int n)
{
	if(n < 0)
	{
		ft_putchr('-');
		ft_putnbr(-n);
	}
	else if(n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchr(n + '0');
	}	
}

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char	*)s);
		}
		s++;
	}
	return (NULL);
}
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sub;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	sub = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (s1[i] != '\0')
	{
		sub[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sub[i + j] = s2[j];
		j++;
	}
	sub[i + j] = '\0';
	return (sub);
}
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

char	*ft_strjoinchr(char *s1, char c)
{
	char	*sub;
	int		i;


	if (!s1)
		return (0);

	i = 0;
	sub = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!sub)
		return (0);
	while (s1[i] != '\0')
	{
		sub[i] = s1[i];
		i++;
	}
	sub[i++] = c;
	sub[i] = '\0';
	return (sub);
}