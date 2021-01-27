/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:08:52 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/27 14:01:50 by ketaouki         ###   ########lyon.fr   */
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

void	ft_star(s_input *s, const char *input, va_list args, va_list copy)
{
	int cpy;

	(s->index)++;
	if (input[s->index] >= '0' || input[s->index] <= '9')
	{
		s->width = va_arg(args, int);
		cpy = va_arg(copy, int);
	}
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

void	ft_dot(s_input *s, const char *input, va_list args, va_list copy)
{
	int cpy;

	s->f_dot = 1;
	(s->index)++;
	if (input[s->index] >= '0' || input[s->index] <= '9')
		ft_precision(s, input);
	if (input[s->index] == '*')
	{
		(s->index)++;
		if (input[s->index] >= '0' || input[s->index] <= '9')
		{
			s->precision = va_arg(args, int);
			cpy = va_arg(copy, int);
		}
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

void	ft_add_in_structure(s_input *s, const char *input, va_list args, va_list copy)
{
	if (input[s->index] == '-' || input[s->index] == '0')
		ft_less_or_zero(s, input);
	ft_width(s, input);
	if (input[s->index] == '*')
		ft_star(s, input, args, copy);
	if (input[s->index] == '.')
		ft_dot(s, input, args, copy);
	if (input[s->index] == 'c' || input[s->index] == 's' ||
			input[s->index] == 'p' || input[s->index] == 'd' ||
			input[s->index] == 'i' || input[s->index] == 'u' ||
			input[s->index] == 'x' || input[s->index] == 'X' ||
			input[s->index] == '%')
	{
		s->type = input[s->index];
		ft_type_count(s, copy);
		(s->index)++;
	}
	if (s->width > s->precision)
		s->width_supp_precision = 1;
}

void	ft_initialise_structure(s_input *s)
{
	s->f_less = 0;
	s->f_zero = 0;
	s->f_dot = 0;
	s->width = 0;
	s->precision = 0;
	s->nbr_char_a_imprime = 0;
	s->negatif = 0;
	s->width_supp_precision = 0;
	s->type = '\0';
}
