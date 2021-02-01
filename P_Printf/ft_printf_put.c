/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:08:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 14:23:53 by ketaouki         ###   ########lyon.fr   */
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

int		ft_putadress_hexa(void *str, char *base)
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
		ft_putchar(dest[i]);
		i++;
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int		ft_putneg(void)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	ft_putchar('-');
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}

int		ft_putnbr(s_input *s, int n)
{
	long	nb;
	int		nb_caractere_imprime;

	nb = (long)n;
	nb_caractere_imprime = 0;
	if (nb == 0 && s->precision == 0 && s->f_dot == 1)
		return (nb_caractere_imprime);
	if (nb < 0)
		nb = nb * -1;
	if (nb > 9)
		ft_putnbr(s, nb / 10);
	ft_putchar((nb % 10) + '0');
	while (n > 9)
	{
		n = n / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}

int		ft_putnbr_base(unsigned int nbr, char *base)
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
		ft_putchar('-');
		nb = nb * -1;
		nb_caractere_imprime++;
	}
	if (nb >= k)
	{
		ft_putnbr_base((nb / k), base);
		nb_caractere_imprime++;
	}
	ft_putchar(base[nb % k]);
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}

int		ft_putnbr_unsigned(s_input *s, int n)
{
	unsigned long	nb;
	int		nb_caractere_imprime;

	nb = (unsigned long)n;
	nb_caractere_imprime = 0;
	if (nb == 0 && s->precision == 0 && s->f_dot == 1)
		return (nb_caractere_imprime);
	if (nb < 0)
		nb = nb * -1;
	if (nb > 9)
		ft_putnbr(s, nb / 10);
	ft_putchar((nb % 10) + '0');
	while (n > 9)
	{
		n = n / 10;
		nb_caractere_imprime++;
	}
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}
