/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 07:39:44 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/17 11:32:45 by ketaouki         ###   ########lyon.fr   */
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

char	*ft_rec(char *str, char c)
{
	char	*rec;
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
		if (!(rec = ft_calloc(sizeof(char), j + 1)))
			return (NULL);
		j = 0;
		while (str[i])
			rec[j++] = str[i++];
		rec[j] = '\0';
		return (rec);
	}
	return (0);
}

int		the_line(char **line, char **save, char **next, int ret)
{
	*line = ft_substr(*save, 0, (ft_len_nl(*save, '\n')));
	*save = ft_substr(*next, 1, ft_strlen(*next));
	return (ret);
}

int		free_error(char **save, int ret)
{
	free(*save);
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save[4096];
	char		*next;
	int			r;

	r = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (save[fd] == NULL)
		if (!(save[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
	while (!(next = ft_rec(save[fd], '\n')))
	{
		if ((r = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*line = ft_substr(save[fd], 0, ft_strlen(save[fd]));
			save[fd] = NULL;
			return (0);
		}
		if (r == -1)
			return (free_error(&save[fd], -1));
		buffer[r] = '\0';
		save[fd] = ft_strjoin(save[fd], buffer);
	}
	return (the_line(line, &save[fd], &next, 1));
}
