/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:08:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/21 08:35:53 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width(s_input *s, const char *input)
{
	s->width = ft_atoi(&input[s->index]);
	while (input[s->index] >= '0' && input[s->index] <= '9')
		(s->index)++;
}

void	ft_precision(s_input *s, const char *input)
{
	if (input[s->index] >= '0' || input[s->index] <= '9')
		s->precision = ft_atoi(&input[s->index]);
	while (input[s->index] >= '0' && input[s->index] <= '9')
		(s->index)++;
}

void	ft_star(s_input *s, const char *input, va_list args)
{
	s->f_star = 1;
	(s->index)++;
	s->width = 1;
	if (input[s->index] >= '0' || input[s->index] <= '9')
		s->width = va_arg(args, int);
	while (input[s->index] >= '0' && input[s->index] <= '9')
		(s->index)++;
}

void	ft_less_or_zero(s_input *s, const char *input)
{
	if (input[s->index] == '-')
	{
		s->index++;
		s->f_less = 1;
		if ((input[s->index]) == '-')
			s->index++;
	}
	if (input[s->index] == '0')
	{
		s->f_zero = 1;
		(s->index)++;
		if ((input[s->index]) == '-')
		{
			s->f_zero = 0;
			s->f_less = 1;
			s->index++;
		}
	}
	s->width = 1;
}

void	ft_dot(s_input *s, const char *input, va_list args)
{
	s->f_dot = 1;
	(s->index)++;
	if (input[s->index] >= '0' || input[s->index] <= '9')
		ft_precision(s, input);
	if (input[s->index] == '*')
	{
		s->f_star = 1;
		(s->index)++;
		if (input[s->index] >= '0' || input[s->index] <= '9')
			s->precision = va_arg(args, int);
		while (input[s->index] >= '0' && input[s->index] <= '9')
			(s->index)++;
	}
	if (input[s->index] == '-')
	{
		(s->index)++;
		ft_precision(s, input);
		s->precision = s->precision * (-1);
	}
}
