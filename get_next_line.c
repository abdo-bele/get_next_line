/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:20:25 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/01 20:54:58 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #define BUFFER_SIZE 100

int	endline(char *p)
{
	int	i;

	i = 0;
	while (p[i] != '\n')
		i++;
	return (i);
}

char	*ft_get_new_len(char *p)
{
	while (*p != '\n')
		p++;
	return (p);
}

char	*ft_read(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*ab;
	size_t		i;

	i = read(fd, buffer, BUFFER_SIZE);
	ab = ft_strdup(buffer);
	return (ab);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*str;
	char		*abdo;
	char		*tmp;
	int			i;

	tmp = ptr;
	str = ft_read(fd);
	ft_memcpy(ptr, str, BUFFER_SIZE);
	i = endline(ptr);
	abdo = malloc(i + 2);
	abdo[i] = '\n';
	abdo[i + 1] = '\0';
	while (i >= 0)
	{
		abdo[i] = ptr[i];
		i--;
	}
	ptr = ft_get_new_len(tmp);
	return (abdo);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

#include <stdio.h>
int main(void)
{
	int fd = open("text.txt", O_RDONLY);
    char *s = get_next_line(fd);
    printf("s : %s\n", s);
    while (s) {
        ft_putstr(s);
        // putchar('\n');
        free(s);
        s = get_next_line(fd);
    }
    return (0);
}