/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/21 08:11:28 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_count(int n)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	if (n < 0)
	{
		n = n * -1;
		nb_caractere_imprime++;
	}
	if (n > 9)
	{
		ft_putnbr_count(n / 10);
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
		nb_caractere_imprime++;
	}
	if (nb >= k)
	{
		ft_putnbr_base_count((nb / k), base);
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

int		ft_type_count(s_input *s, va_list copy)
{
	char			*str;
	int				integer;
	unsigned int	numunsigned;
	int				nb_caractere_imprime;

	nb_caractere_imprime = 0;
	integer = 0;
	numunsigned = 0;
	if (s->type == 'c')
	{
		integer = va_arg(copy, int);
		nb_caractere_imprime++;
	}
	if (s->type == 's')
	{
		str = va_arg(copy, char *);
		nb_caractere_imprime += ft_putstr_count(str);
	}
	if (s->type == 'p')
	{
		str = va_arg(copy, void *);
		nb_caractere_imprime += 2;
		nb_caractere_imprime += ft_putadress_hexa_count(str, "0123456789abcdef");
	}
	if (s->type == 'd')
	{
		integer = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_count(integer);
	}
	if (s->type == 'i')
	{
		integer = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_count(integer);
	}
	if (s->type == 'u')
	{
		numunsigned = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_base_count(numunsigned, "0123456789");
	}
	if (s->type == 'x')
	{
		numunsigned = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_base_count(numunsigned, "0123456789abcdef");
	}
	if (s->type == 'X')
	{
		numunsigned = va_arg(copy, int);
		nb_caractere_imprime += ft_putnbr_base_count(numunsigned, "0123456789ABCDEF");
	}
	if (s->type == '%')
	{
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}
