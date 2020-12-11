/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:07:32 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/10 15:32:18 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	get_next_line(int fd, char **line)
{
	char		tmp[BUFFER_SIZE + 1];
	static char	*save;
	int			r;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || *line == NULL) // CAS ERREUR
		return (-1);
	if (save == NULL)
		save = calloc((BUFFER_SIZE + 1), sizeof(char));
	while ((r = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		save = ft_strjoin(save, tmp);
	}
	*line = ft_strjoin(save, *line);
	//printf("line : %s\n", *line);
	printf("save : %s\n", save);
	// save = ft_substr(tmp,);

	if (r == -1) //CAS ERREUR LORS DE LA LECTURE
			return (-1);
	if (r == 0) //FIN DE LECTURE
			return (0);
	return (0);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 256);
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < 5)
	{
		//printf("str before : %s\n", str);
		get_next_line(fd, &str);
		//printf("str after : %s\n", str);
		free(str);
		str = 0;
	 	i++;
	}

	/*while(1)
	;*/
    return 0;
}
