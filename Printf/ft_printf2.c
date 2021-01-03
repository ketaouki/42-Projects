#include <stdio.h>
#include "ft_printf.h"

void	ft_indicator(const char *input, va_list args)
{
	if (*input >= '1' || *input <= '9')
		//ft_atoi(input);
		printf("%d", ft_atoi(input));

}

void	ft_type(const char *input, va_list args)
{
	char *str;
	int integer;
	unsigned int numunsigned;
	int count;

	count = 0;
	integer = 0;
	numunsigned = 0;
	if (*input == 'c')
	{
		integer = va_arg(args, int);
		ft_putchar(integer);
	}
	if (*input == 's')
	{
		str = va_arg(args, char *);
		ft_putstr(str);
	}
	if(*input == 'p')
	{
		str = va_arg(args, void *);
		ft_putstr("0x");
		ft_putadress_hexa(str, "0123456789abcdef");
	}
	if (*input == 'd')
	{
		integer = va_arg(args, int);
		ft_putnbr(integer);
	}
	if (*input == 'i')
	{
		integer = va_arg(args, int);
		ft_putnbr(integer);
	}
	if (*input == 'u')
	{
		numunsigned = va_arg(args, int);
		ft_putnbr_base(numunsigned, "0123456789");
	}
	if (*input == 'x')
	{
		numunsigned = va_arg(args, int);
		ft_putnbr_base(numunsigned, "0123456789abcdef");
	}
	if (*input == 'X')
	{
		numunsigned = va_arg(args, int);
		ft_putnbr_base(numunsigned, "0123456789ABCDEF");
	}
	if (*input == '%')
	{
		ft_putchar('%');
	}
}

void	ft_readinput(const char *input, va_list args)
{
	while (*input)
	{
		if (*input == '%') // si il y a une conv a faire
		{
			input++;
			if (*input == '0' || *input == '-' || *input == '.' ||
				*input == '*' || (*input >= '0' || *input <= '9'))
			{
				ft_indicator(input, args);
				input++;
			}
			if (*input == 'c' || *input == 's' || *input == 'p' ||
				*input == 'd' || *input == 'i' || *input == 'u' ||
				*input == 'x' || *input == 'X' || *input == '%')
			{
				ft_type(input, args);
				input++;
			}
		}
		else
		{
			ft_putchar(*input);
			input++;
		}
	}
}

int	ft_printf(const char *input, ...)
{
	va_list args;
	va_start(args, input); // 1er arg
	ft_readinput(input, args);

	va_end(args);
	return (0); // doit return le nombre de charactere affiché
}
