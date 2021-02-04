/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:08:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/04 09:15:30 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &c, 1);
}

int		ft_putnbr_unsigned(s_input *s, unsigned int n)
{
	unsigned int	nb;
	int				nb_caractere_imprime;

	nb = n;
	nb_caractere_imprime = 0;
	if (nb == 0 && s->precision == 0 && s->f_dot == 1)
		return (nb_caractere_imprime);
	if (nb > 9)
		ft_putnbr_unsigned(s, nb / 10);
	ft_putchar((nb % 10) + '0');
	while (n > 9)
	{
		n = n / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}
