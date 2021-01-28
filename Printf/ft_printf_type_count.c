/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:50:20 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/27 10:27:48 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char_type_count(s_input *s, va_list copy)
{
	int	c;

	c = va_arg(copy, int);
	s->nbr_char_a_imprime++;
}

void	ft_d_i_type_count(s_input *s, va_list copy)
{
	int	integer;

	integer = va_arg(copy, int);
	if (integer < 0)
	{
		s->negatif = 1;
		s->nbr_char_a_imprime -= 1;
	}
	s->nbr_char_a_imprime += ft_putnbr_count(s, integer);
	if (integer <= -2147483648)
		s->nbr_char_a_imprime = 10;
}

void	ft_type_count(s_input *s, va_list copy)
{
	if (s->type == 'c')
		ft_char_type_count(s, copy);
	if (s->type == 'd' || s->type == 'i')
		ft_d_i_type_count(s, copy);
}
