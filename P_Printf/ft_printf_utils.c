/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:09:22 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/20 11:09:39 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_structure(s_input *s)
{
	s->f_less = 0;
	s->f_zero = 0;
	s->f_dot = 0;
	s->f_star = 0;
	s->width = 0;
	s->precision = 0;
	s->type = '\0';
}

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &d, 1);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	res;

	i = 0;
	n = 1;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	res = res * n;
	return (res);
}
