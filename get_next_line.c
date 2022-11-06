/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:20:25 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/06 12:00:36 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *left_str)
{
	char	*buff;
	int		n;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = 1;
	while (!ft_strchr(left_str, '\n') && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*ab;
	static char	*abdo;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	abdo = ft_read_file(fd, abdo);
	if (!abdo)
		return (NULL);
	ab = ft_get_line(abdo);
	abdo = ft_get_next_line(abdo);

	return (ab);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("text.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	while (s != NULL)
// 	{
// 		printf("get ab = %s\n", s);
// 		free(s);
// 		s = get_next_line(fd);
// 	}

// 	return (0);
// }
