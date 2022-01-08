/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:46:37 by gbertin           #+#    #+#             */
/*   Updated: 2022/01/08 16:00:20 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_strlen(char *s);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
int		*ft_strchr(char *s, int c);

char	*ft_saveline(char *str);
char	*ft_cutline(char *str);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif