/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:50:20 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/26 08:48:04 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_type_count(va_list copy)
{
	int	c;
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	c = va_arg(copy, int);
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}

int	ft_str_p_type_count(s_input *s, va_list copy)
{
	char	*str;
	int		nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->type == 's')
	{
		str = va_arg(copy, char *);
		nb_caractere_imprime += ft_putstr_count(str);
	}
	if (s->type == 'p')
	{
		str = va_arg(copy, void *);
		nb_caractere_imprime += 2;
		nb_caractere_imprime += ft_putadress_hexa_count(str, "0123456789abcdef");
	}
	return (nb_caractere_imprime);
}

int	ft_d_i_type_count(va_list copy)
{
	int	nb_caractere_imprime;
	int	integer;

	nb_caractere_imprime = 0;
	integer = va_arg(copy, int);
	if (integer < 0)
		ft_putchar('-');
	nb_caractere_imprime += ft_putnbr_count(integer);
	return (nb_caractere_imprime);
}

int	ft_u_x_type_count(s_input *s, va_list copy)
{
	int				nb_caractere_imprime;
	unsigned int	numunsigned;

	numunsigned = 0;
	nb_caractere_imprime = 0;
	if (s->type == 'u')
	{
		numunsigned = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_base_count(numunsigned, "0123456789");
	}
	if (s->type == 'x')
	{
		numunsigned = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_base_count(numunsigned, "0123456789abcdef");
	}
	if (s->type == 'X')
	{
		numunsigned = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_base_count(numunsigned, "0123456789ABCDEF");
	}
	return (nb_caractere_imprime);
}

int	ft_type_count(s_input *s, va_list copy)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->type == 'c')
		nb_caractere_imprime += ft_char_type_count(copy);
	if (s->type == 's' || s->type == 'p')
		nb_caractere_imprime += ft_str_p_type_count(s, copy);
	if (s->type == 'd' || s->type == 'i')
		nb_caractere_imprime += ft_d_i_type_count(copy);
	if (s->type == 'u' || s->type == 'x' || s->type == 'X')
		nb_caractere_imprime += ft_u_x_type_count(s, copy);
	if (s->type == '%')
		nb_caractere_imprime++;
	return (nb_caractere_imprime);
}
