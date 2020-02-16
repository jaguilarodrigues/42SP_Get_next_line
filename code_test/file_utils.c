/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:45:50 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 01:47:30 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

void	ft_putstr(char *s, int fd)
{
	while(*s)
	{
		write(fd, s++, 1);
	}
}

void	ft_putchr( char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n, int fd)
{
	int	num;
	
	if(n < 0)
	{
		ft_putchr('-', fd);
		ft_putnbr(-n, fd);
	}
	else if(n > 9)
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
	else
	{
		ft_putchr(n + '0', fd);
	}	
}