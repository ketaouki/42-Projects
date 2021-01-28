/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:36:40 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/28 10:40:37 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_type(s_input *s, va_list args)
{
	int	c;
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	c = va_arg(args, int);
	ft_putchar(c);
	nb_caractere_imprime++;
	s->type = '\0';
	return (nb_caractere_imprime);
}

int	ft_str_p_type(s_input *s, va_list args)
{
	char	*str;
	int		nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->type == 's')
	{
		str = va_arg(args, char *);
		nb_caractere_imprime += ft_putstr(str);
	}
	s->type = '\0';
	return (nb_caractere_imprime);
}

int	ft_d_i_type(s_input *s, va_list args)
{
	int	nb_caractere_imprime;
	int	integer;

	integer = 0;
	nb_caractere_imprime = 0;
	integer = va_arg(args, int);
	if (s->negatif == 1)
	{
		integer *= -1;
		s->negatif = 0;
	}
	nb_caractere_imprime += ft_putnbr(s, integer);
	if (integer <= -2147483648)
		nb_caractere_imprime = 10;
	s->type = '\0';
	return (nb_caractere_imprime);
}

int	ft_type(s_input *s, va_list args)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->type == 'c')
		nb_caractere_imprime += ft_char_type(s, args);
	if (s->type == 's')
		nb_caractere_imprime += ft_str_p_type(s, args);
	if (s->type == 'd' || s->type == 'i')
		nb_caractere_imprime += ft_d_i_type(s, args);
	if (s->type == '%')
	{
		ft_putchar('%');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}
