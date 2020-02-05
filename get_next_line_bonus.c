/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:08:03 by avarnier          #+#    #+#             */
/*   Updated: 2020/02/05 14:14:54 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!(cpy = (char *)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen_nl(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		cpy[i] = s2[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	free(s1);
	return (cpy);
}

static char	*ft_strdup(char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen_nl(s) + 1))))
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char buffer[OPEN_MAX][BUFFER_SIZE + 1];

	*line = ft_strdup(buffer);
	if (fd < 0 || !line || read(fd, buffer[fd], 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	ret = BUFFER_SIZE;
	if (ft_strchr(buffer[fd], '\n') == 0)
	{
		while ((ret = read(fd, buffer[fd], BUFFER_SIZE)) > 0)
		{
			buffer[fd][ret] = '\0';
			*line = ft_strjoin(*line, buffer[fd]);
			if (ft_strchr(buffer[fd], '\n') != 0)
				break ;
		}
	}
	if (ret < BUFFER_SIZE && ft_strchr(buffer[fd], '\n') == 0)
	{
		ft_bzero(buffer[fd], BUFFER_SIZE + 1);
		return (0);
	}
	ft_memmove(buffer[fd], buffer[fd] + ft_strlen_nl(buffer[fd]) + 1,
	ft_strlen(buffer[fd]) - ft_strlen_nl(buffer[fd]));
	return (1);
}
