/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 08:50:20 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 12:45:37 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_p_type_count(s_input *s, va_list copy)
{
	char	*str;

	if (s->type == 's')
	{
		str = va_arg(copy, char *);
		s->nbr_char_a_imprime += ft_putstr_count(s, str);
	}
}


void	ft_type_count(s_input *s, va_list copy)
{
	if (s->type == 's')
		ft_str_p_type_count(s, copy);
}
