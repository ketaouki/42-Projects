/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:52:57 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/28 10:06:12 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_less_only(s_input *s, va_list args)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->negatif == 1)
		nb_caractere_imprime += ft_putneg();
	nb_caractere_imprime += ft_type(s, args);
	while ((nb_caractere_imprime) < s->width)
	{
		ft_putchar(' ');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int	ft_dot_only(s_input *s, va_list args)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->negatif == 1)
		ft_putchar('-');
	while ((nb_caractere_imprime + s->nbr_char_a_imprime) < s->precision)
	{
		ft_putchar('0');
		nb_caractere_imprime++;
	}
	if (s->negatif == 1)
		nb_caractere_imprime++;
	nb_caractere_imprime += ft_type(s, args);
	return (nb_caractere_imprime);
}

int	ft_zero_only(s_input *s, va_list args)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->negatif == 1)
		ft_putchar('-');
	while ((nb_caractere_imprime + s->negatif) + s->nbr_char_a_imprime < s->width)
	{
		ft_putchar('0');
		nb_caractere_imprime++;
	}
	if (s->negatif == 1)
		nb_caractere_imprime++;
	nb_caractere_imprime += ft_type(s, args);
	return (nb_caractere_imprime);
}

int	ft_less_dot(s_input *s, va_list args)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->precision >= s->width)
		nb_caractere_imprime += ft_dot_only(s, args);
	if (s->precision < s->width)
	{
		nb_caractere_imprime += ft_dot_only(s, args);
		while (nb_caractere_imprime < s->width)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
	}
	return (nb_caractere_imprime);
}

int	ft_width_supp_precision(s_input *s, va_list args)
{
	int nb_caractere_imprime;
	int tempo;

	tempo = 0;
	nb_caractere_imprime = 0;
	if (s->precision == 0 && s->f_dot == 1 && s->negatif == 1)
	{
		tempo += s->negatif;
		nb_caractere_imprime--;
	}
	while (tempo + s->negatif < (s->width - (s->precision)))
	{
		ft_putchar(' ');
		tempo++;
	}
	if (s->negatif == 1)
		ft_putchar('-');
	while ((nb_caractere_imprime + s->nbr_char_a_imprime) < (s->precision))
	{
		ft_putchar('0');
		nb_caractere_imprime++;
	}
	if (s->negatif == 1)
		nb_caractere_imprime++;
	nb_caractere_imprime += ft_type(s, args);
	nb_caractere_imprime += tempo;
	return (nb_caractere_imprime);
}

int	gestion_flag(s_input *s, va_list args)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->f_less == 1 && s->f_zero == 1)
		s->f_zero = 0;
	if (s->f_less == 1 && s->f_dot == 0 && s->f_zero == 0)
		nb_caractere_imprime += ft_less_only(s, args);
	if (s->f_less == 0 && s->f_dot == 1 && s->width_supp_precision == 0)
		nb_caractere_imprime += ft_dot_only(s, args);
	if (s->f_less == 0 && s->f_dot == 1 && s->width_supp_precision == 1)
		nb_caractere_imprime += ft_width_supp_precision(s, args);
	if (s->f_less == 0 && s->f_dot == 0 && s->f_zero == 1)
		nb_caractere_imprime += ft_zero_only(s, args);
	if (s->f_less == 1 && s->f_dot == 1 && s->f_zero == 0)
		nb_caractere_imprime += ft_less_dot(s, args);
	return (nb_caractere_imprime);
}

int	ft_print(s_input *s, va_list args)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	nb_caractere_imprime += gestion_flag(s, args);
	while ((nb_caractere_imprime) + s->nbr_char_a_imprime < s->width)
	{
		ft_putchar(' ');
		nb_caractere_imprime++;
	}
	if (s->type == 'c' || s->type == 's' || s->type == 'p' ||
		s->type == 'd' || s->type == 'i' || s->type == 'u' ||
		s->type == 'x' || s->type == 'X' || s->type == '%')
	{
		if (s->negatif == 1)
			nb_caractere_imprime += ft_putneg();
		nb_caractere_imprime += ft_type(s, args);
	}
	if (s->width < 0)
	{
		s->width *= -1;
		while (nb_caractere_imprime < s->width)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
	}
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
			// printf("nbr char  = %d\n", s->nbr_char_a_imprime);
			nb_caractere_imprime += ft_print(s, args);
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
