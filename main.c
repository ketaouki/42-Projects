#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	//while (i < 10)
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	while (1)
		;
	return (0);
}


