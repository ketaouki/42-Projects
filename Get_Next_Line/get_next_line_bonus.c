/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 07:39:44 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/16 07:55:11 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_len_nl(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_recup(char *str, char c)
{
	char	*recup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c && str[i])
	{
		while (str[i + j])
			j++;
		recup = ft_calloc(sizeof(char), j + 1);
		j = 0;
		while (str[i])
			recup[j++] = str[i++];
		recup[j] = '\0';
		return (recup);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save[4096];
	char		*next;
	int			lecture;

	lecture = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (save[fd] == NULL)
		if (!(save[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
	while (!(next = ft_recup(save[fd], '\n')))
	{
		if ((lecture = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*line = ft_substr(save[fd], 0, ft_strlen(save[fd]));
			save[fd] = NULL;
			return (0);
		}
		if (lecture == -1)
			return (-1);
		buffer[lecture] = '\0';
		save[fd] = ft_strjoin(save[fd], buffer);
	}
	*line = ft_substr(save[fd], 0, (ft_len_nl(save[fd], '\n')));
	save[fd] = ft_substr(next, 1, ft_strlen(next));
	return (1);
}
