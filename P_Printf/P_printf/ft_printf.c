/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:52:57 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/23 09:49:19 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_less_only(s_input *s, va_list args)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = ft_type(s, args);
	while ((nb_caractere_imprime) < s->width)
	{
		ft_putchar(' ');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int	ft_dot_only(s_input *s, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	int	count;

	nb_caractere_imprime = 0;
	count = ft_type_count(s, copy);
	while ((nb_caractere_imprime) + count < s->precision)
	{
		ft_putchar('0');
		nb_caractere_imprime++;
	}
	nb_caractere_imprime += ft_type(s, args);
	return (nb_caractere_imprime);
}

int	ft_zero_only(s_input *s, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	int	count;

	nb_caractere_imprime = 0;
	count = ft_type_count(s, copy);
	while ((nb_caractere_imprime) + count < s->width)
	{
		ft_putchar('0');
		nb_caractere_imprime++;
	}
	nb_caractere_imprime += ft_type(s, args);
	return (nb_caractere_imprime);
}

int	ft_less_dot(s_input *s, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	int	count;

	nb_caractere_imprime = 0;
	count = ft_type_count(s, copy);
	while ((nb_caractere_imprime) + count < s->precision)
	{
		ft_putchar('0');
		nb_caractere_imprime++;
	}
	nb_caractere_imprime += ft_type(s, args);
	while ((nb_caractere_imprime) < s->width)
	{
		ft_putchar(' ');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int	ft_print(s_input *s, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	int test;

	test = 0;
	nb_caractere_imprime = 0;
	if (s->f_less == 1 && s->f_dot == 0)
		nb_caractere_imprime += ft_less_only(s, args);
	if (s->f_less == 1 && s->f_dot == 1)
		nb_caractere_imprime += ft_less_dot(s, args, copy);
	if (s->f_dot == 1 && s->f_less == 0)
		nb_caractere_imprime += ft_dot_only(s, args, copy);
	if (s->f_zero == 1 && s->f_less == 0 && s->f_dot == 0)
		nb_caractere_imprime += ft_zero_only(s, args, copy);
	if (s->width)
	{
		test = ft_type_count(s, copy);
		while ((nb_caractere_imprime) + test < s->width)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(s, args);
		if (s->width < 0)
		{
			s->width *= -1;
			while ((nb_caractere_imprime) < s->width)
			{
				ft_putchar(' ');
				nb_caractere_imprime++;
			}
		}
	}
	if (s->type == 'c' || s->type == 's' || s->type == 'p' ||
		s->type == 'd' || s->type == 'i' || s->type == 'u' ||
		s->type == 'x' || s->type == 'X' || s->type == '%')
		nb_caractere_imprime += ft_type(s, args);
	return (nb_caractere_imprime);
}

int	read_input(const char *input, va_list args, s_input *s, va_list copy)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	while (input[s->index])
	{
		if (input[s->index] == '%')
		{
			(s->index)++;
			ft_initialise_structure(s);
			ft_add_in_structure(s, input, args, copy);
			// printf("\nflag less = %d\n",s->f_less);
			// printf("flag zero = %d\n",s->f_zero);
			// printf("flag dot  = %d\n",s->f_dot);
			// printf("flag star = %d\n",s->f_star);
			// printf("largeur   = %d\n",s->width);
			// printf("precision = %d\n",s->precision);
			// printf("type 	  = %c\n",s->type);
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

int	ft_printf(const char *input, ...)
{
	int		nb_caractere_imprime;
	va_list	args;
	va_list	copy;
	s_input	s;

	s.index = 0;
	va_start(args, input);
	va_copy(copy, args);
	nb_caractere_imprime = read_input(input, args, &s, copy);
	va_end(args);
	return (nb_caractere_imprime);
}
