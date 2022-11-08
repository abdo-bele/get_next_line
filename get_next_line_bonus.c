/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:33:46 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/08 14:47:24 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *abdo)
{
	char	*buff;
	int		n;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = 1;
	while (!ft_strchr(abdo, '\n') && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		abdo = ft_strjoin(abdo, buff);
	}
	free(buff);
	return (abdo);
}

char	*get_next_line(int fd)
{
	char		*ab;
	static char	*abdo[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	abdo[fd] = ft_read_file(fd, abdo[fd]);
	if (!abdo[fd])
		return (NULL);
	ab = fft_get_line(abdo[fd]);
	abdo[fd] = fft_get_next_line(abdo[fd]);
	return (ab);
}
