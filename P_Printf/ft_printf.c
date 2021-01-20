/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:08:18 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/20 11:12:40 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lecture_chaine(const char *input, va_list args, va_list copy, s_input *s)
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
	s_input s;

	s.index = 0;
	va_start(args, input);
	va_copy(copy, args);
	nb_caractere_imprime = lecture_chaine(input, args, copy, &s);
	va_end(args);
	return (nb_caractere_imprime);
}
