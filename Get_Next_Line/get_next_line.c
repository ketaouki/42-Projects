/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:07:32 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/11 09:46:28 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len_nl(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*sauvegarde;
	int			r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (sauvegarde == NULL)
		sauvegarde = calloc((BUFFER_SIZE + 1), sizeof(char));
	while ((!(ft_strchr(sauvegarde, '\n')) && (r = read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		sauvegarde = ft_strjoin(sauvegarde, buffer);
	}
	*line = ft_substr(sauvegarde, 0, (ft_len_nl(sauvegarde, '\n')));
	sauvegarde = ft_substr(ft_strchr(sauvegarde, '\n'), 0, ft_strlen(ft_strchr(sauvegarde,'\n')));
	if (r == -1)
			return (-1);
	if (r == 0)
			return (0);
	return (1);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 256);
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < 10)
	{
		printf("str before : %s\n", str);
		get_next_line(fd, &str);
		//printf("str after : %s\n", str);
		free(str);
	 	i++;
	}

	while(1)
		;
    return 0;
}
