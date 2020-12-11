/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:51:38 by ketaouki          #+#    #+#             */
/*   Updated: 2020/12/05 13:40:45 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	return (s2);
}
