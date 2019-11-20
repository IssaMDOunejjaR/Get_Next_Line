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
    while (str[j] != '\n' && str[j])
        j++;
    tmp = malloc((sizeof(char) * j) + 1);
    while (i < j) 
    {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

int     join(char *buffer, char **save, char **line, int fd)
{
    char *tmp;
    char *s;

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

int     get_next_line(int fd, char **line)
{
    static char *save[4864];
    int i;
    char buffer[BUFFER_SIZE + 1];
    char *s;

    if (fd < 0 || !line || BUFFER_SIZE < 0 || fd > 4864)
        return (-1);
    if (!save[fd])
        save[fd] = ft_strdup("");
    while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[i] = '\0';
        if (join(buffer, save, line, fd))
            return (1);
    }
    if (i < 0)
        return (-1);
    if (save[fd] && (s = ft_strchr(save[fd], '\n')))
    {
        *line = locate(save[fd]);
        save[fd] = s;
        return (1);
    }
    *line = save[fd];
    return (0);
}

int main()
{
    char *str;
    int fd = open("test.txt", O_RDONLY);
    int fd2 = open("big.txt", O_RDONLY);
    int i = 1;


    while(get_next_line(fd2, &str) > 0)
    {
        printf("line %d = %s\n", i, str);
        free(str);
        i++;
    }
    printf("line %d = %s\n", i, str);
    //printf("get = %d\n", get_next_line(40000, &str));
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    // printf("get = %d\n", get_next_line(fd, &str));
    // printf("line = %s\n", str);
    return 0;
}