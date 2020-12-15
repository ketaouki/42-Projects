#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (char *)malloc(size * nmemb)))
		return (0);
	while (i < (size * nmemb))
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		j;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	k = 0;
	if (!(dest = malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (s1[j])
	{
		dest[k++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		dest[k++] = s2[j++];
	}
	dest[k] = '\0';
	free(s1);
	return (dest);
}


char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len)
			s2[i++] = s[start++];
	}
	s2[i] = '\0';
	free(s);
	return (s2);
}

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char		*tab;
// 	size_t		i;
// 	size_t		s_len;

// 	if (!s)
// 		return (0);
// 	s_len = ft_strlen(s);
// 	if (s_len < start)
// 	{
// 		if (!(tab = ft_calloc(sizeof(char), 1)))
// 			return (0);
// 		tab[0] = '\0';
// 		return (tab);
// 	}
// 	if (!(tab = ft_calloc(sizeof(char), len + 1)))
// 		return (0);
// 	i = 0;
// 	while (i < len)
// 	{
// 		tab[i] = s[start + i];
// 		i++;
// 	}
// 	tab[i] = '\0';
// 	free(s);
// 	return (tab);
// }

char	*ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)str + (i + 1));
		i++;
	}
	return (NULL);
}
