/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writefile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 01:48:08 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 01:49:11 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libfile.h"

int		main()
{
	int fd;
	fd = open("42", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR );
	if(fd == -1)
	{
		ft_putstr("FAIO OPEN\n", 1);
		return(1);
	}
	ft_putnbr(fd, 1);
	ft_putstr("AMENO\n", fd);
	if(close(fd)== -1)
	{
		ft_putstr("FAIO CLOSE\n", 1);
		return (1);
	}	
	return (0);
}