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

int     get_next_line(int fd, char **line)
{
    static char *save[4864];
    int i;
    char *buffer;
    char *result;
    char *s;

    buffer = malloc(BUFFER_SIZE + 1);
    while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (!save[fd])
            save[fd] = ft_strdup("");
        buffer[i] = '\0';
        result = ft_strjoin(save[fd], buffer);
        if ((s = ft_strchr(result, '\n')))
        {
            save[fd] = s;
            *line = locate(result);
            return (1);
        }
        else
            save[fd] = result;
    }
    if (save[fd])
    {
        *line = locate(save[fd]);
        save[fd] = ft_strchr(save[fd], '\n');
        return (1);
    }
    return (0);
}
 
int main()
{
    char *str;
    int fd = open("test.txt", O_RDONLY);
    int fd2 = open("big.txt", O_RDONLY);
    int i = 1;

    while(get_next_line(fd2, &str))
    {
        printf("line %d = %s\n", i, str);
        i++;
    }
    return 0;
}