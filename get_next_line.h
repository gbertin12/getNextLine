/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:46:37 by gbertin           #+#    #+#             */
/*   Updated: 2021/12/11 08:51:41 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//a retirer avant le rendu
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char    *get_next_line(int fd);
int     ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2);
void    *ft_memalloc(size_t size);
void    ft_bzero(char *s1, size_t n);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#endif