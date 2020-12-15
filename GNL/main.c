#include "get_next_line.h"

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
		//get_next_line(fd, &line);
		//printf("%d\n", get_next_line(fd, &line));
		printf("%s\n", line);
		//i++;
		//printf("line ==>%s<==> Valeur ==>%d\n", line, get_next_line(fd, &line));
		free(line);
		line = NULL;
	}
	//printf("%d\n", get_next_line(fd, &line));
	while (1)
		;
	return (0);
}


