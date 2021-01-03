#include "ft_printf.h"

int	ft_type(const char ***input, va_list args)
{
	char *str;
	int integer;
	unsigned int numunsigned;
	int nb_caractere_imprime;

	nb_caractere_imprime = 0;
	integer = 0;
	numunsigned = 0;
	if (***input == 'c')
	{
		integer = va_arg(args, int);
		ft_putchar(integer);
		nb_caractere_imprime++;
		(**input)++;
	}
	if (***input == 's')
	{
		str = va_arg(args, char *);
		nb_caractere_imprime += ft_putstr(str);
		(**input)++;
	}
	if(***input == 'p')
	{
		str = va_arg(args, void *);
		ft_putstr("0x");
		nb_caractere_imprime += 2;
		nb_caractere_imprime += ft_putadress_hexa(str, "0123456789abcdef");
		(**input)++;
	}
	if (***input == 'd')
	{
		integer = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr(integer);
		(**input)++;
	}
	if (***input == 'i')
	{
		integer = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr(integer);
		input++;
	}
	if (***input == 'u')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789");
		(**input)++;
	}
	if (***input == 'x')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789abcdef");
		(**input)++;
	}
	if (***input == 'X')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789ABCDEF");
		(**input)++;
	}
	if (***input == '%')
	{
		ft_putchar('%');
		nb_caractere_imprime++;
		(**input)++;
	}
	return (nb_caractere_imprime);
}
