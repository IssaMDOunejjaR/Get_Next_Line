/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:09:19 by iounejja          #+#    #+#             */
/*   Updated: 2019/11/13 12:09:20 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 100

int	   locate_index(const char *s, int c)
{
	int		i;
	char	*str;

	i = 1;
	str = (char*)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if (str[i] == (char)c)
		return (i);
	return (0);
}

char    *locate(char *str)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    j = locate_index(str, '\n') ? locate_index(str, '\n') : locate_index(str, '\0');
    tmp = malloc((sizeof(char) * j) + 1);
    while (i < j) 
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

int     get_next_line(int fd, char **line)
{
    static char *save[4864];
    int i;
    char *buffer;
    char *result;
    char *tmp;
    char *s;

    buffer = malloc(BUFFER_SIZE + 1);
    while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        /*if (i == 0 && !save[fd])
            return (0);*/
        if (!save[fd])
            save[fd] = malloc(sizeof(char) * 1);
        buffer[i] = '\0';
        result = ft_strjoin(save[fd], buffer);
        if ((s = ft_strchr(result, '\n')))
        {
            //*s = '\0';
            //tmp = result;
            result = locate(result);
            //save[fd] = ft_strchr(tmp, '\n');
            save[fd] = s;
            *line = result;
            return (1);
        }
        else
            save[fd] = result;
    }
    if (save[fd])
    {
        tmp = save[fd];
        result = locate(save[fd]);
        save[fd] = ft_strchr(tmp, '\n');
        *line = result;
        return (1);
    }
    return (0);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    int fd2 = open("big.txt", O_RDONLY);
    char *str;
    int i = 1;

    while (get_next_line (fd, &str) > 0)
    {
        printf("line %d = %s\n", i,str);
        i++;
    }
    /*get_next_line(fd, &str);
    printf("line = %s\n", str);
    get_next_line(fd2, &str);
    printf("line = %s\n", str);
    get_next_line(fd, &str);
    printf("line = %s\n", str);
    get_next_line(fd2, &str);
    printf("line = %s\n", str);*/
    return (0);
}