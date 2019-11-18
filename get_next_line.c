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

char    *locate(char *str)
{
    int i;
    int j;
    char *tmp;

    i = 0;
    j = 0;
    while (str[i] != '\n' && str[i])
        i++;
    tmp = malloc((sizeof(char) * i) + 1);
    while (j < i)
    {
        tmp[j] = str[j];
        j++;
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


    buffer = malloc(BUFFER_SIZE + 1);
    if (fd < 0)
        return -1;
    while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
       
        if (i == 0 && !save[fd])
            return (0);
        if (!save[fd])
            save[fd] = malloc(sizeof(char) * 1);
        buffer[i] = '\0';
        result = ft_strjoin(save[fd], buffer);
        if (ft_strchr(result, '\n'))
        {
            tmp = result;
            result = locate(result);
            save[fd] = ft_strchr(tmp, '\n');
            *line = result;
            return (1);
        }
        else
            save[fd] = result;
    }
    if (i < 0)
        return (-1);
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
    char *str;
    int fd = open("test.txt", O_RDONLY);
    while(get_next_line(fd, &str))
    {
        printf("\n%s",str);
        free(str);
    }
    return 0;
}