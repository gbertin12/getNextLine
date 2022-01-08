/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:48:58 by gbertin           #+#    #+#             */
/*   Updated: 2022/01/08 15:54:21 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cutline(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_saveline(char *str)
{
	int		i;
	int		y;
	char	*new;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i] || (str[i] == '\n' && str[i + 1] == '\0'))
	{
		free(str);
		return (NULL);
	}
	if (ft_strlen(str + i) == 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	i++;
	y = 0;
	while (str[i] != '\0')
		new[y++] = str[i++];
	new[y] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	char static		*save;
	char			*line_ret;
	char			buff[BUFFER_SIZE + 1];
	int				end_buffer;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	end_buffer = 1;
	while (!ft_strchr(save, '\n') && end_buffer != 0)
	{
		end_buffer = read(fd, buff, BUFFER_SIZE);
		if (end_buffer == -1 || (end_buffer == 0 && !save))
			return (NULL);
		buff[end_buffer] = '\0';
		save = ft_strjoin(save, buff);
	}
	if (!save)
		return (NULL);
	line_ret = ft_cutline(save);
	save = ft_saveline(save);
	return (line_ret);
}
