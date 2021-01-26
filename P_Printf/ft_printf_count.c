/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/26 10:58:10 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_count(int n)
{
	long	nb;
	int		nb_caractere_imprime;

	nb = (long)n;
	nb_caractere_imprime = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		n = n * -1;
		nb_caractere_imprime++;
	}
	if (nb > 9)
		ft_putnbr_count(nb / 10);
	while (n > 9)
	{
		n = n / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}
