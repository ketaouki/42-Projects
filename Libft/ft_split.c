/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:39:20 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/05 13:46:19 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_countline(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i++])
		if ((s[i] == c || s[i] == '\0') && s[i - 1] != c)
			k++;
	return (k);
}

static int			ft_countchar(char const *s, char c, int i)
{
	int k;

	k = 0;
	while (s[i + k] && s[i + k] != c)
		k++;
	return (k);
}

static char			**ft_d(char const *s, char c, char **str, int line)
{
	int i;
	int k;
	int y;

	i = 0;
	y = 0;
	k = 0;
	while (k < line)
	{
		y = 0;
		while (s[i] == c && s[i])
			i++;
		if (!(str[k] = malloc(sizeof(char) * ((ft_countchar(s, c, i)) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			str[k][y++] = s[i++];
		str[k][y] = '\0';
		k++;
	}
	str[k] = 0;
	return (str);
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	int		k;

	if (s == NULL)
		return (NULL);
	k = ft_countline(s, c);
	if (!(str = malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	str = ft_d(s, c, str, k);
	return (str);
}
