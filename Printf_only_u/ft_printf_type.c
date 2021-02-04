/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:36:40 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/04 07:38:23 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_u_x_type(s_input *s, va_list args)
{
	int				nb_caractere_imprime;
	unsigned long	numunsigned;

	numunsigned = 0;
	nb_caractere_imprime = 0;
	if (s->type == 'u')
	{
		numunsigned = va_arg(args, long);
		nb_caractere_imprime += ft_putnbr_unsigned(s, numunsigned);
	}
	s->type = '\0';
	return (nb_caractere_imprime);
}

int	ft_type(s_input *s, va_list args)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (s->type == 'u' || s->type == 'x' || s->type == 'X')
		nb_caractere_imprime += ft_u_x_type(s, args);
	return (nb_caractere_imprime);
}
