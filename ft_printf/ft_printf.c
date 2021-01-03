#include <stdio.h>
#include "ft_printf.h"

int	ft_conversion(const char **input, va_list args, va_list copy)
{
	int nb_caractere_imprime;
	int taille;
	int test;

	taille = 0;
	nb_caractere_imprime = 0;
	test = 0;


	if (**input == '-') // si j'ai un moins espace = a la fin.
	{
		(*input)++;
		if (**input >= '0' && **input <= '9')
		{
				taille = ft_atoi(*input);
				while (**input >= '0' && **input <= '9')
				(*input)++;
		}
		nb_caractere_imprime = ft_type(&input, args);
		while (nb_caractere_imprime < taille)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
	}



	if (**input == '0' || **input == '.') // si j'ai un 0 ou . = padding
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



	if(**input == '*') // si j'ai une asterix
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


	if (**input >= '1' && **input <= '9') // si on me donne juste un nombre
	{
		taille = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
		test = ft_type_count(&input, copy);
		while ((nb_caractere_imprime + test) < taille)
		{
			ft_putchar(' ');
			nb_caractere_imprime++;
		}
		nb_caractere_imprime += ft_type(&input, args);
	}


	if (**input == 'c' || **input == 's' || **input == 'p' || // si j'ai juste une conversion
				**input == 'd' || **input == 'i' || **input == 'u' ||
				**input == 'x' || **input == 'X' || **input == '%')
			nb_caractere_imprime = ft_type(&input, args);
	return (nb_caractere_imprime);
}

int	lecture_chaine(const char *input, va_list args, va_list copy)
{
	int nb_caractere_imprime;

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
	int nb_caractere_imprime;
	va_list args;
	va_list copy;

	va_start(args, input);
	va_copy(copy, args);
	nb_caractere_imprime = lecture_chaine(input, args, copy);

	va_end(args);
	return (nb_caractere_imprime);
}
