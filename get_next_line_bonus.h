/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 21:12:37 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/05/06 00:18:53 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_findchar(char *str, char c);
char	*ft_calloc(int size);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);

#endif
