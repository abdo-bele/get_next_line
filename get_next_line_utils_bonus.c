/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:19:43 by aarchtou          #+#    #+#             */
/*   Updated: 2022/11/04 19:25:47 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*ptr;

	i = 0;
	l = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
		ptr[l++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[l++] = s2[i++];
	ptr[l] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_get_line(char *abdo)
{
	int		i;
	char	*str;

	i = 0;
	if (!abdo[i])
		return (NULL);
	while (abdo[i] && abdo[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (abdo[i] && abdo[i] != '\n')
	{
		str[i] = abdo[i];
		i++;
	}
	if (abdo[i] == '\n')
	{
		str[i] = abdo[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_abdo(char *abdo)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (abdo[i] && abdo[i] != '\n')
		i++;
	if (!abdo[i])
	{
		free(abdo);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(abdo) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (abdo[i])
		str[j++] = abdo[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}