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
	int		i;
	int		j;
	int		l_s1;
	int		l_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
    l_s1 = ft_strlen(s1);
    l_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[l_s1 + l_s2] = '\0';
	return (str);
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