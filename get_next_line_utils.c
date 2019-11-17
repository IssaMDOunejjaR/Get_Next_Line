/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:09:34 by iounejja          #+#    #+#             */
/*   Updated: 2019/11/13 12:09:36 by iounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

void    ft_putchar_fd(int fd, char c)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(int fd, char *str)
{
    int i;

    i = 0;
    while (str[i])
        ft_putchar_fd(fd, str[i++]);
}

char    *ft_strdup(const char *s1)
{
    int i;
    int l_s1;
    char *str;

    i = 0;
    l_s1 = ft_strlen(s1);
    str = malloc((sizeof(char) * l_s1) + 1);
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l_s1;
	int		l_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
    l_s1 = ft_strlen(s1);
    l_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, (void*)s1, l_s1);
	ft_memmove(str + l_s1, (void*)s2, l_s2);
	str[l_s1 + l_s2] = '\0';
	return (str);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (ft_memcmp(dst, src, len) == 0)
		return (dst);
	if (dst > src)
	{
		while (len--)
		{
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
		}
		return (dst);
	}
	while (i < len)
	{
		*(unsigned char*)(dst + i) = *(unsigned char*)(src + i);
		i++;
	}
	return (dst);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i + 1]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (0);
}