/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:07:32 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/11 15:23:36 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len_nl(char *str, char c)
{
	int i;

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

 int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*sauvegarde;
	int			lecture;

	lecture = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	if (sauvegarde == NULL)
		sauvegarde = calloc((BUFFER_SIZE + 1), sizeof(char));
	while (((!ft_strchr(sauvegarde, '\n')) && (lecture = read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		sauvegarde = ft_strjoin(sauvegarde, buffer);
	}
	if (!ft_strchr(sauvegarde, '\n'))
	{
		*line = ft_strdup(sauvegarde);
		return (0);
	}
	*line = ft_substr(sauvegarde, 0, (ft_len_nl(sauvegarde, '\n')));
	sauvegarde = ft_substr(ft_strchr(sauvegarde, '\n'), 0, ft_strlen(ft_strchr(sauvegarde,'\n')));
	return (1);
}


// int	main(void)
// {
// 	int		fd;
// 	char	*str;

// 	str = malloc(sizeof(char) * 256);
// 	fd = open("text.txt", O_RDONLY);
// 	while (get_next_line(fd, &str))
// 	{
// 		printf("str after : %s\n", str);
// 		free(str);
// 	}
// 	get_next_line(fd, &str);
// 	printf("str after : %s\n", str);
// 	while(1)
// 		;
//     return 0;
// }
