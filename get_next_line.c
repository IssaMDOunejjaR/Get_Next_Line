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

#define BUFFER_SIZE 10

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

    if (!save[fd])
        save[fd] = malloc(sizeof(char) * 1);
    buffer = malloc(BUFFER_SIZE + 1);
    while ((i = read(fd, buffer, BUFFER_SIZE)))
    {
        buffer[i] = '\0';
        result = ft_strjoin(save[fd], buffer);
        printf("result = %s\n", result);
        printf("###################################################\n");
        if (ft_strchr(buffer, '\n'))
        {
            tmp = result;
            result = locate(buffer);
            save[fd] = ft_strchr(buffer, '\n');
            printf("save = %s\n", save[fd]);
            *line = result;
            return (1);
        }
    }
    if (save[fd])
    {
        tmp = save[fd];
        result = locate(save[fd]);
        save[fd] = ft_strchr(tmp, '\n');
        *line = result;
        return (1);
    }
    return (1);
}

int main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str;
    /*while (get_next_line (fd, &str) > 0)
        printf("line = %s\n", str);*/
    get_next_line(fd, &str);
    printf("line = %s\n", str);
    get_next_line(fd, &str);
    printf("line = %s\n", str);
    return (0);
}