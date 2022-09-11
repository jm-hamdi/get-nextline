/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:11:30 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/02/16 19:11:44 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int ft_strichr(char *tmp, char c)
// {
//     int i;

//     i = 0;
//     while (tmp[i])
//     {
//         if(tmp[i] == c)
//             return (i-1);
//         i++;
//     }
//     return(i);
// }

int ft_strlen(char *str)
{
    int i;

    i=0;
    while (str[i])
        i++;
    return (i);
}
char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}


int ft_strchr(char *tmp, char c)
{
    int i;

    if (!tmp)
        return (0);
    i = 0;
    while (tmp[i])
    {
        if(tmp[i] == c)
            return (1);
        i++;
    }
    return (0);
}


char    *ft_strjoin(char *s, char *p)
{
    char    *str;
    int i;
    int j;

    if (!s)
        return(ft_strdup(p));
    if (!p)
        return (ft_strdup(s));
     str = (char *)malloc(sizeof(char ) * (ft_strlen(s) + ft_strlen(p) + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while(s[i])
    {
        str[i] = s[i];
         i++;
    }
    while (p[j])
    {
        str[i + j] = p[j];
         j++;
    }
    str[i + j] = '\0';
    return (str);
}
