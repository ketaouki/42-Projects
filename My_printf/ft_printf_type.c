/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:36:40 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/23 12:31:58 by ketaouki         ###   ########lyon.fr   */
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
	if (s->type == 'p')
	{
		str = va_arg(args, void *);
		ft_putstr("0x");
		nb_caractere_imprime += 2;
		nb_caractere_imprime += ft_putadress_hexa(str, "0123456789abcdef");
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
	if (integer < 0)
	{
		integer = integer * -1;
		if (!(s->width > s->precision))
		{
			ft_putchar('0');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime++;
	}
	nb_caractere_imprime += ft_putnbr(integer);
	s->type = '\0';
	return (nb_caractere_imprime);
}

int	ft_u_x_type(s_input *s, va_list args)
{
	int				nb_caractere_imprime;
	unsigned int	numunsigned;

	numunsigned = 0;
	nb_caractere_imprime = 0;
	if (s->type == 'u')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789");
	}
	if (s->type == 'x')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789abcdef");
	}
	if (s->type == 'X')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789ABCDEF");
	}
	s->type = '\0';
	return (nb_caractere_imprime);
}

int	ft_type(s_input *s, va_list args)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->type == 'c')
		nb_caractere_imprime += ft_char_type(s, args);
	if (s->type == 's' || s->type == 'p')
		nb_caractere_imprime += ft_str_p_type(s, args);
	if (s->type == 'd' || s->type == 'i')
		nb_caractere_imprime += ft_d_i_type(s, args);
	if (s->type == 'u' || s->type == 'x' || s->type == 'X')
		nb_caractere_imprime += ft_u_x_type(s, args);
	if (s->type == '%')
	{
		ft_putchar('%');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}
