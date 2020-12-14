#include "get_next_line.h"

int main (void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		//printf("%d\n", get_next_line(fd, &line));
		//printf("%s\n", line);
		//printf("line ==>%s<==> Valeur ==>%d\n", line, get_next_line(fd, &line));
		write(1, line, 1);
		write(1, "\n", 1);
		free(line);
	}
	// while (1)
	// 	;
	return (0);
}


