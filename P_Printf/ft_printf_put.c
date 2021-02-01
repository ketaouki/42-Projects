/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:08:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 13:14:12 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &c, 1);
}

int		ft_putstr(s_input *s, char *str)
{
	int	i;
	int	nb_caractere_imprime;

	i = 0;
	nb_caractere_imprime = 0;
	if (str == NULL)
		str = "(null)";
	if (s->f_dot == 1)
	{
		if (s->f_dot == 1 && s->precision < 0)
		{
			while (str[i])
			{
				ft_putchar(str[i]);
				i++;
				nb_caractere_imprime++;
			}
			return (nb_caractere_imprime);
		}
		while (str[i] && i < s->precision)
		{
			ft_putchar(str[i]);
			i++;
			nb_caractere_imprime++;
		}
		return (nb_caractere_imprime);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}
