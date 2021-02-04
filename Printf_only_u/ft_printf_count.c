/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/04 09:15:25 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_count_unsigned(s_input *s, unsigned int n)
{
	unsigned int	nb;
	int				nb_caractere_imprime;

	nb = n;
	nb_caractere_imprime = 0;
	if (nb == 0 && s->precision == 0 && s->f_dot == 1)
	{
		nb_caractere_imprime++;
		return (nb_caractere_imprime);
	}
	if (nb > 9)
		ft_putnbr_count_unsigned(s, nb / 10);
	while (n > 9)
	{
		n = n / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}
