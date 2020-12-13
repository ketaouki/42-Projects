#include "get_next_line.h"


int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	char		*next;
	int			lecture;

	lecture = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (save == NULL)
		save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(next = ft_strchr(save, '\n')) && (lecture = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		save = ft_strjoin(save, buffer);
	}
	if (!ft_strchr(save, '\n'))
	{
		*line = ft_substr(save, 0, ft_strlen(save));
		return (0);
	}
	*line = ft_substr(save, 0, (ft_len_nl(save, '\n')));
	free(save);
	save = ft_substr(next, 0, ft_strlen(next));
	return (1);
}
