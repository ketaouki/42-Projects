#include <stdio.h>
#include "ft_printf.h"

int	ft_conversion(const char **input, va_list args)
{
	int nb_caractere_imprime;
	int integer;
	int taille;

	integer = 0;
	taille = 0;
	nb_caractere_imprime = 0;
	if (**input == '-')
		(*input)++;
	if (**input >= '0' && **input <= '9')
	{
		taille = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	nb_caractere_imprime = ft_type(&input, args);
		/*if (**input == 'd')
		{
			integer = va_arg(args, int);
			nb_caractere_imprime += ft_putnbr(integer);
			(*input)++;
		}*/
	while (nb_caractere_imprime < taille)
	{
		ft_putchar(' ');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}

int	lecture_chaine(const char *input, va_list args)
{
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			nb_caractere_imprime += ft_conversion(&input, args);
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

	va_start(args, input);
	nb_caractere_imprime = lecture_chaine(input, args);

	va_end(args);
	return (nb_caractere_imprime);
}
