/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:50:46 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 02:07:37 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

//#define BUF_SIZE 4096
#define BUF_SIZE 10

int		main()
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	
	fd = open("text", O_RDONLY);
	if(fd == -1)
	{
		ft_putstr("FAIO OPEN\n", 1);
		return(1);
	}
	//ret = read(fd, buf, BUF_SIZE);
	//buf[ret] = '\0';
	//ft_putnbr(fd, 1);
	//ft_putchr('\n', 1);
	//ft_putstr(buf, 1);
	while((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		//ft_putnbr(fd, 1);
		ft_putchr('\n', 1);
		ft_putstr(buf, 1);
	}
	if(close(fd)== -1)
	{
		ft_putstr("FAIO CLOSE\n", 1);
		return (1);
	}	
	return (0);
}