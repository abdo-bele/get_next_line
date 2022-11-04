/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:19:30 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/04 19:30:43 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// #define BUFFER_SIZE 100

char	*ft_read_file(int fd, char	*abdo)
{
	char		*bufer;
	int			i;

	bufer = malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (NULL);
	i = 1;
	while (!ft_strchr(abdo, '\n') && i != 0)
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i == -1)
		{
			free(bufer);
			return (NULL);
		}
		bufer[i] = '\0';
		abdo = ft_strjoin(abdo, bufer);
	}
	free(bufer);
	return (abdo);
}

char	*get_next_line(int fd)
{
	static char	*abdo[10240];
	char		*ab;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	abdo = ft_read_file(fd, abdo);
	if (!abdo)
		return (NULL);
	ab = ft_get_line(abdo);
	abdo = ft_new_left_str(abdo);
	return (ab);
}


// int	main(void)
// {
// 	int		fd = open("text.txt", O_RDONLY);
// 	int i = 6;
// 	char	*s = get_next_line(fd);
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	while (s != NULL && i > 0)
// 	{
// 		printf("get line = %s\n", s);
// 		free(s);
// 		s = get_next_line(fd);
// 		i--;
// 	}

// 	return (0);
// }
