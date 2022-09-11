/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm-hamdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:09:20 by jm-hamdi          #+#    #+#             */
/*   Updated: 2022/02/16 19:09:28 by jm-hamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_readline(char *p,int fd)
{
    int     i;
    // char *str;
    char    *buf;

    i = 1;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
     if (!buf)
         return (NULL);
    while (i > 0 && !ft_strchr(p, '\n'))
    {
        i = read(fd, buf, BUFFER_SIZE);
        // printf("read : %d\n", i);
        if (i == 0)
            break ;
        if (i < 0)
        {
            free(buf);
            return (NULL);
        }
        buf[i] = '\0';
        // printf("buffer : %s\n", buf);
         if (buf)
            p = ft_strjoin(p, buf);
        //  printf("%s\n", buf);
    }
    free(buf);
    return (p);
}

char    *ft_cherch_line(char *t)
{
    int     i;
    int     j;
    char    *l;

    i = 0;
    j = 0;
    if (!t)
        return (NULL);
    if (t[0] == '\0')
        return (NULL);
    while (t[i] != '\0' && t[i] != '\n')
        i++;
    if (t[i] == '\n')
        i++;
    l = (char *)malloc(sizeof(char) * (i + 1));
    if (!l)
        return (NULL);
    while (j < i)
    {
        l[j] = t[j];
        j++;
    }
    l[j] = '\0';
    return (l);
}

char	*ft_rest(char *str)
{
    int     i;
    int     j;
    char    *rest;

    i = 0;
    j = 0;
    if (!str)
        return (NULL);
    if (str[i] == '\0')
        return (NULL);
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    rest = (char *)malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
    if (!rest)
        return (NULL);
    while (str[i])
        rest[j++] = str[i++];
    rest[j] = '\0';
    if (str[0] == '\0')
    {
        free (rest);
        return (NULL);
    }
    return (rest);
}

char    *get_next_line(int fd)
{
    char        *l;
    char *t;
    static char *s;

    t = NULL;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    t = ft_readline(s,fd);
    //   printf("%s",t);
    if (t == NULL)
        return (NULL);
    l = ft_cherch_line(t);
    s = ft_rest(t);
    return (l);
}


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char *p;
    int fd;
    int i = 29;

    fd = open("file.txt", O_CREAT, O_RDONLY);
    //printf("%d",fd);
    while(i--)
    {

    p = get_next_line(fd);
    printf("%s",p);
    }
}
