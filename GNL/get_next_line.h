#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#include <fcntl.h>

int get_next_line(int fd, char **line);
int	ft_len_nl(char *str, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char c);

#endif
