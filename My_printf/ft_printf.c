/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:12:56 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/18 09:58:00 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(const char **input, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	int	taille;
	int	test;

	taille = 0;
	nb_caractere_imprime = 0;
	test = 0;
	if (**input == '-')
	{
		(*input)++;
		if (**input >= '0' && **input <= '9')
		{
			taille = ft_atoi(*input);
			while (**input >= '0' && **input <= '9')
				(*input)++;
		}
		if (**input == '*')
		{
			(*input)++;
			taille = va_arg(args, int);
			if (taille < 0)
			{
				taille *= -1;
				nb_caractere_imprime = ft_type(&input, args);
				while (nb_caractere_imprime < taille)
				{
					ft_putchar(' ');
					nb_caractere_imprime++;
				}
			}
		}
		if (**input == '.')
		{
			(*input)++;
			if (**input >= '0' && **input <= '9')
			{
				taille = ft_atoi(*input);
				while (**input >= '0' && **input <= '9')
					(*input)++;
			}
			test = ft_type_count(&input, copy);
			while ((nb_caractere_imprime + test) < taille)
			{
				ft_putchar('0');
				nb_caractere_imprime++;
			}
		}
		if (**input == 'c' || **input == 's' || **input == 'p' ||
				**input == 'd' || **input == 'i' || **input == 'u' ||
				**input == 'x' || **input == 'X' || **input == '%')
			nb_caractere_imprime = ft_type(&input, args);
		while (nb_caractere_imprime < taille)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
		while (**input)
		{
			if (**input == '%')
			{
			(*input)++;
			nb_caractere_imprime += ft_conversion(input, args, copy);
			}
			ft_putchar(**input);
			(*input)++;
			nb_caractere_imprime++;
		}
	}
	if (**input == '0' || **input == '.')
	{
		(*input)++;
		if (**input == '.')
			(*input)++;
		if (**input >= '0' && **input <= '9')
		{
			taille = ft_atoi(*input);
			while (**input >= '0' && **input <= '9')
				(*input)++;
		}
		test = ft_type_count(&input, copy);
		while ((nb_caractere_imprime + test) < taille)
		{
			ft_putchar('0');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(&input, args);
	}
	if (**input == '*')
	{
		(*input)++;
		taille = va_arg(args, int);
		if (taille < 0)
		{
			taille *= -1;
			nb_caractere_imprime = ft_type(&input, args);
			while (nb_caractere_imprime < taille)
			{
				ft_putchar(' ');
				nb_caractere_imprime++;
			}
		}
		test = ft_type_count(&input, copy);
		while ((nb_caractere_imprime + test) < taille)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(&input, args);
	}
	if (**input >= '1' && **input <= '9')
	{
		taille = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
		if (**input == '.')
		{
			(*input)++;
			if (**input >= '0' && **input <= '9')
			{
				taille = ft_atoi(*input);
				while (**input >= '0' && **input <= '9')
					(*input)++;
			}
			test = ft_type_count(&input, copy);
			while ((nb_caractere_imprime + test) < taille)
			{
				ft_putchar('0');
				nb_caractere_imprime++;
			}
		}
		test = ft_type_count(&input, copy);
		while ((nb_caractere_imprime + test) < taille)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(&input, args);
	}
	if (**input == 'c' || **input == 's' || **input == 'p' ||
				**input == 'd' || **input == 'i' || **input == 'u' ||
				**input == 'x' || **input == 'X' || **input == '%')
		nb_caractere_imprime = ft_type(&input, args);
	return (nb_caractere_imprime);
}

int	lecture_chaine(const char *input, va_list args, va_list copy)
{
	int	nb_caractere_imprime;

	nb_caractere_imprime = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			nb_caractere_imprime += ft_conversion(&input, args, copy);
		}
		else
		{
			ft_putchar(*input);
			input++;
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

	va_start(args, input);
	va_copy(copy, args);
	nb_caractere_imprime = lecture_chaine(input, args, copy);
	va_end(args);
	return (nb_caractere_imprime);
}
