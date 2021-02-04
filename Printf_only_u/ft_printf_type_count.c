/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:50:20 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/04 09:24:00 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_u_x_type_count(s_input *s, va_list copy)
{
	unsigned int	numunsigned;

	numunsigned = 0;
	if (s->type == 'u')
	{
		numunsigned = va_arg(copy, int);
		if (numunsigned > 4294967294)
			s->unsign = 0;
		else
			s->unsign = 1;
		s->nbr_char_a_imprime += ft_putnbr_count_unsigned(s, numunsigned);
	}
}

void	ft_type_count(s_input *s, va_list copy)
{
	if (s->type == 'u' || s->type == 'x' || s->type == 'X')
		ft_u_x_type_count(s, copy);
}
