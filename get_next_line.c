/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:48:58 by gbertin           #+#    #+#             */
/*   Updated: 2022/01/08 01:44:48 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
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
	while(str[i] != '\n' && str[i])
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
	// printf("start : %x\n", str);
	// printf("new : %x\n", new);
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
	if (!str[i])
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

char	*ft_reading_file(int fd, char *save)
{
	char	*buffer;
	int		end_buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	end_buffer = 1;
	while (!ft_strchr(save, '\n') && end_buffer != 0)
	{
		end_buffer = read(fd, buffer, BUFFER_SIZE);
	//printf("start :%s\n", buffer);
		if (end_buffer == -1 || (end_buffer == 0 && !save))
		{
			free(buffer);
			return (NULL);
		}
		buffer[end_buffer] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char    		*line_return;
	static char		*line_save;
	
	line_return = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//printf("\n________________\nreturn before read:%s", line_save);
	line_save = ft_reading_file(fd, line_save);
	if (!line_save)
		return (NULL);
	//printf("\nreturn :%s", line_save);
	if (line_save[0] == '\n' && line_save[1] == '\0')
	{
		free(line_save);
		free(line_return);
		return (NULL);
	}	
	line_return = ft_cutline(line_save);
	//printf("before :%s\n", line_save);
	//if (ft_strchr(line_save, '\n'))
		//printf("il y a un backslash\n");
	line_save = ft_saveline(line_save);
	//printf("after :%s\n", line_save);
	return (line_return);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str;
	str = get_next_line(fd);
	printf("\nprint : %s\n_______________\n", str);
	str = get_next_line(fd);
	printf("\nprint : %s\n_______________\n", str);
	str = get_next_line(fd);
	printf("\nprint :%s\n_______________\n", str);
	str = get_next_line(fd);
	printf("\nprint :%s\n_______________\n", str);
	str = get_next_line(fd);
	printf("\nprint :%s\n_______________\n", str);
	str = get_next_line(fd);
	printf("\nprint :%s\n_______________\n", str);
	str = get_next_line(fd);
	close(fd);
    return (0);
}