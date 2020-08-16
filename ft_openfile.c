/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 00:34:52 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 01:48:46 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfile.h"

int		main()
{
	int fd;
	fd = open("text", O_RDONLY);
	if(fd == -1)
	{
		ft_putstr("FAIO OPEN\n", 1);
		return(1);
	}
	ft_putnbr(fd, 1);
	if(close(fd)== -1)
	{
		ft_putstr("FAIO CLOSE\n", 1);
		return (1);
	}	
	return (0);
}