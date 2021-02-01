/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 12:54:26 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_count(s_input *s, char *str)
{
	int	i;
	int	nb_caractere_imprime;

	i = 0;
	nb_caractere_imprime = 0;
	if (str)
	{
		if (s->f_dot == 1)
		{
			while (str[i] && i < s->precision)
			{
				i++;
				nb_caractere_imprime++;
			}
			return (nb_caractere_imprime);
		}
		while (str[i])
		{
			i++;
			nb_caractere_imprime++;
		}
	}
	if (str == NULL)
		nb_caractere_imprime = 6;
	return (nb_caractere_imprime);
}
