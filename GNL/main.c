#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%d", get_next_line(fd, &line));
		printf("%s\n", line);
		free(line);
	}
	// while (1)
	// 	;
	return (0);
}


