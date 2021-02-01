/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 09:35:41 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_putstr_count(char *str)
{
	int	i;
	int	nb_caractere_imprime;

	i = 0;
	nb_caractere_imprime = 0;
	if (str)
	{
		while (str[i])
		{
			i++;
			nb_caractere_imprime++;
		}
	}
	return (nb_caractere_imprime);
}

int		ft_putnbr_base_count(unsigned int nbr, char *base)
{
	int				i;
	unsigned int	k;
	unsigned int	nb;
	int				nb_caractere_imprime;

	i = 0;
	nb = nbr;
	k = ft_strlen(base);
	nb_caractere_imprime = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		nbr = nbr * -1;
		nb_caractere_imprime++;
	}
	if (nb >= k)
		ft_putnbr_base_count((nb / k), base);
	while (nbr > 9)
	{
		nbr = nbr / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
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
	dest[i] = base[((nb % 10))];
	while (i < 9)
	{
		i++;
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int		ft_putnbr_count_unsigned(s_input *s, int n)
{
	unsigned long	nb;
	int		nb_caractere_imprime;

	nb = (unsigned long)n;
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

