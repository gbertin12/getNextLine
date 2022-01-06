
   
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:49:46 by gbertin           #+#    #+#             */
/*   Updated: 2021/12/06 22:32:10 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int     ft_strlen(char *s)
{
	size_t  i;

	i = 0;
	if (!s)
		return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
	unsigned int  size;
	char    *new;
	size_t  i;
	size_t  j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0'; 
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(size);
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}