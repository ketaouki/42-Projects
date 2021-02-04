/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/04 10:27:56 by ketaouki         ###   ########lyon.fr   */
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

int		ft_putadress_hexa_count(void *str, char *base)
{
	char			dest[9];
	int				i;
	unsigned long	nb;
	int				nb_caractere_imprime;

	nb = (unsigned long)str;
	i = 8;
	nb_caractere_imprime = 0;
	while ((nb / ft_strlen(base) > 0))
	{
		dest[i] = base[((nb % ft_strlen(base)))];
		nb = nb / ft_strlen(base);
		i--;
	}
	dest[i] = base[((nb % ft_strlen(base)))];
	while (i < 9)
	{
		i++;
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int		ft_putnbr_count(s_input *s, int n)
{
	long	nb;
	int		nb_caractere_imprime;

	nb = (long)n;
	nb_caractere_imprime = 0;
	if (nb == 0 && s->precision == 0 && s->f_dot == 1)
	{
		nb_caractere_imprime++;
		return (nb_caractere_imprime);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		n = n * -1;
		nb_caractere_imprime++;
	}
	if (nb > 9)
		ft_putnbr_count(s, nb / 10);
	while (n > 9)
	{
		n = n / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}

int		ft_putnbr_count_unsigned(s_input *s, unsigned int n)
{
	unsigned int	nb;
	int				nb_caractere_imprime;

	nb = n;
	nb_caractere_imprime = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		n = n * -1;
		nb_caractere_imprime++;
	}
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

int		ft_putnbr_base_count(s_input *s, unsigned int nbr, char *base)
{
	unsigned int	len_base;
	unsigned int	nb;
	int				nb_caractere_imprime;

	nb = nbr;
	len_base = ft_strlen(base);
	nb_caractere_imprime = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		nb_caractere_imprime++;
	}
	if (nb == 0 && s->precision == 0 && s->f_dot == 1)
	{
		nb_caractere_imprime++;
		return (nb_caractere_imprime);
	}
	if (nb >= len_base)
	{
		ft_putnbr_base_count(s, (nb / len_base), base);
	}
	while (nbr >= len_base)
	{
		nbr = nbr / len_base;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}
