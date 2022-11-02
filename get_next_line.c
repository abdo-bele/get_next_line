/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:20:25 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/02 18:53:47 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// #define BUFFER_SIZE 100
int	endline(char *ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_new_len(char *p)
{
	int		i;
	int		a;
	char	*str;

	i = endline(p);
	a = 0;
	str = ft_substr(p, i + 1, i);
	free(p);
	return (str);
}


char	*ft_dup(char	*h)
{
	int		i;
	int		a;
	char	*abdo;

	i = endline(h);
	a = 0;
	if (i != -1)
	{
		abdo = malloc(i + 1);
		if (!abdo)
			return (NULL);
		ft_memcpy(abdo, h, i);
		// while (h[a++] && i--)
		// 	abdo[a] = h[a];
		abdo[i + 1] = '\0';
	}
	else if (*h != '\n' && i == -1)
	{
		abdo = ft_strdup(h);
		free(h);
	}
	else
		return (free(h), NULL);
	return (abdo);
}

char	*get_next_line(int fd)
{
	static char	*abdo;
	char		*str;
	char		*ab;
	int			n;

	abdo = ft_strdup("");

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	n = 1;
	while (endline(abdo) == -1 && n >= 0)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (str[0]== '\0')
			return (NULL);
		if (n == -1 || n == 0)
			return (free(str), NULL);
		str[n] = '\0';
		abdo = ft_strjoin(abdo, str);
		// free(str);
	}
	ab = ft_dup(abdo);
	return (ab);
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

int	main(void)
{
	int		fd = open("text.txt", O_RDONLY);
	char	*s = get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	while (s != NULL)
	{
		printf("get line = %s\n", s);
		free(s);
		s = get_next_line(fd);
	}

	return (0);
}
