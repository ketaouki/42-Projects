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

char	*ft_recup(char *str, char c)
{
	char	*recup;
	int i;
	int j;

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
		while(str[i])
			recup[j++] = str[i++];
		recup[j] = '\0';
		return (recup);
	}
	return (0);
}

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
		if(!(save = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
	while (!(next = ft_recup(save, '\n')))
	{
		if ((lecture = read(fd, buffer, BUFFER_SIZE)) == 0)
		{
			*line = ft_substr(save, 0, ft_strlen(save));
			save = NULL;
			return (0);
		}
		if (lecture == - 1)
			return (-1);
		buffer[lecture] = '\0';
		save = ft_strjoin(save, buffer);
	}
	*line = ft_substr(save, 0, (ft_len_nl(save, '\n')));
	save = ft_substr(next, 1, ft_strlen(next));
	return (1);
}
