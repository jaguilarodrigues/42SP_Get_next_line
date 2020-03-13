/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:17:04 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/03/13 01:01:03 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_findchar(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_calloc(int size)
{
	char	*a;
	int		i;

	i = 0;
	a = malloc((size + 1) * sizeof(char));
	while (i < size)
		a[i++] = '\0';
	return (a);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		ls1;
	int		ls2;
	char	*ns;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	ns = ft_calloc(ls1 + ls2 + 1);
	if (!ns)
		return (0);
	while (i < ls1)
	{
		ns[i] = s1[i];
		i++;
	}
	while (j < ls2)
	{
		ns[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (ns);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*a;

	i = 0;
	a = (char *)malloc(len + 1 * sizeof(char));
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}