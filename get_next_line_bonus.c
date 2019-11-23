/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:09:19 by iounejja          #+#    #+#             */
/*   Updated: 2019/11/22 17:34:34 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*locate(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j] != '\n' && str[j])
		j++;
	tmp = malloc((sizeof(char) * j) + 1);
	if (!tmp)
		return (NULL);
	while (i < j)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int		join(char *buffer, char **save, char **line, int fd)
{
	char	*tmp;
	char	*s;

	s = save[fd];
	save[fd] = ft_strjoin(save[fd], buffer);
	free(s);
	tmp = save[fd];
	if ((s = ft_strchr(save[fd], '\n')))
	{
		*line = locate(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	return (0);
}

int		rest(char **line, char **save, int fd)
{
	char *tmp;
	char *s;

	tmp = save[fd];
	if ((s = ft_strchr(save[fd], '\n')))
	{
		*line = locate(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	else if (save[fd])
	{
		*line = save[fd];
		save[fd] = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static	char	*save[4864];
	int				i;
	char			*buffer;

	if (fd < 0 || !line || BUFFER_SIZE < 0 || fd > 4864)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (-1);
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = '\0';
		if (join(buffer, save, line, fd))
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	if (i < 0)
		return (-1);
	return (rest(line, save, fd));
}
