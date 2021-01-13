#include "ft_printf.h"

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
