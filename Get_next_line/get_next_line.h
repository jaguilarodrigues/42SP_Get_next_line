/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 21:39:05 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/17 21:26:26 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

//# define BUFFER_SIZE 4000

int		get_next_line(int fd, char **line);
void	ft_putchr(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
void	ft_putfile(int fd);
void	ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_strjoinchr(char *s1, char c);
#endif
