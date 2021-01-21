/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:08:18 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/21 08:32:42 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_in_structure(s_input *s, const char *input, va_list args)
{
	if (input[s->index] == '-' || input[s->index] == '0')
		ft_less_or_zero(s, input);
	ft_width(s, input);
	if (input[s->index] == '*')
		ft_star(s, input, args);
	if (input[s->index] == '.')
		ft_dot(s, input, args);
	if (input[s->index] == 'c' || input[s->index] == 's' ||
			input[s->index] == 'p' || input[s->index] == 'd' ||
			input[s->index] == 'i' || input[s->index] == 'u' ||
			input[s->index] == 'x' || input[s->index] == 'X' ||
			input[s->index] == '%')
	{
		s->type = input[s->index];
		(s->index)++;
	}
}

int		ft_print(s_input *s, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	int test;

	test = 0;
	nb_caractere_imprime = 0;

	if (s->f_less == 1)
	{
		if (s->f_dot == 1)
		{
			if (s->precision < 0)
			{
				nb_caractere_imprime += ft_type(s, args);
				while (nb_caractere_imprime < (s->precision * (-1)))
				{
					ft_putchar(' ');
					nb_caractere_imprime++;
				}
			}
			test = ft_type_count(s, copy);
			while((nb_caractere_imprime) + test < s->precision)
			{
				ft_putchar('0');
				nb_caractere_imprime++;
			}
		}
		nb_caractere_imprime += ft_type(s, args);
		while ((nb_caractere_imprime) < s->width)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
	}
	if (s->f_dot == 1)
	{
		test = ft_type_count(s, copy);
		while((nb_caractere_imprime) + test < s->precision)
		{
			ft_putchar('0');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(s, args);
	}
	if (s->f_zero == 1)
	{
		test = ft_type_count(s, copy);
		while((nb_caractere_imprime) + test < s->width)
		{
			ft_putchar('0');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(s, args);
	}
	if (s->width > 0)
	{
		test = ft_type_count(s, copy);
		while((nb_caractere_imprime) + test < s->width)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(s, args);
	}
	if (s->type == 'c' || s->type == 's' || s->type == 'p' ||
		s->type == 'd' || s->type == 'i' || s->type == 'u' ||
		s->type == 'x' || s->type == 'X' || s->type == '%')
		nb_caractere_imprime += ft_type(s, args);
	return (nb_caractere_imprime);
}

int		read_input(const char *input, va_list args, s_input *s, va_list copy)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	while (input[s->index])
	{
		if (input[s->index] == '%')
		{
			(s->index)++;
			ft_initialise_structure(s);
			ft_add_in_structure(s, input, args);
			nb_caractere_imprime += ft_print(s, args, copy);
		}
		else
		{
			ft_putchar(input[s->index]);
			(s->index)++;
			nb_caractere_imprime++;
		}
	}
	return (nb_caractere_imprime);
}

int		ft_printf(const char *input, ...)
{
	int		nb_caractere_imprime;
	va_list	args;
	va_list	copy;
	s_input s;

	s.index = 0;
	va_start(args, input);
	va_copy(copy, args);
	nb_caractere_imprime = read_input(input, args, &s, copy);
	va_end(args);
	return (nb_caractere_imprime);
}
