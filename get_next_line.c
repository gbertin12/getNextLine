/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:48:58 by gbertin           #+#    #+#             */
/*   Updated: 2022/01/04 20:07:29 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
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
	int		size;
	char	*new;

	size = 0;
	if (!str)
		return (NULL);
	while (str[size] != '\n' && str[size])
		size++;
	new = (char *)malloc(sizeof(char) * size + 2);
	if (!new)
		return (NULL);
	size = 0;
	while(str[size] != '\n' && str[size])
	{
		new[size] = str[size];
		size++;
	}
	if (str[size] == '\n')
	{
		new[size] = '\n';
		size++;
	}
	new[size] = '\0';
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
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	y = 0;
	while (str[i] != '\0')
		new[y++] = str[++i];
	new[y] = '\0';
	free(str);
	return (new);
}
char	*ft_read(int fd, char *save)
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
		if (end_buffer == -1)
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
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_save = ft_read(fd, line_save);
	if (!line_save)
		return (NULL);
	line_return = ft_cutline(line_return);
	line_save = ft_saveline(line_return);
	return (line_return);
}

int	main(void)
{
	int		fd;
	char	*str;
	
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	return (0);
}


// int main()
// {
// 	printf("bonsoir");
//     int fd = open("test.txt", O_RDONLY);
//     char *str;
//     while ((str = get_next_line(fd)) != NULL)
//     {
//         printf("%s", str);
//     }
// 	close(fd);
//     return (0);
// }
