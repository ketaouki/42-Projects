#include "ft_printf.h"

int	ft_conversion(const char *input, va_list args)
{
	char *str;
	int integer;
	unsigned int numunsigned;
	int count;

	count = 0;
	integer = 0;
	numunsigned = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 'c')
			{
				integer = va_arg(args, int);
				ft_putchar(integer);
				input++;
				count++;
			}
			if (*input == 's')
			{
				str = va_arg(args, char *);
				ft_putstr(str);
				input++;
				count++;
			}
			if(*input == 'p')
			{
				str = va_arg(args, void *);
				ft_putstr("0x");
				ft_putadress_hexa(str, "0123456789abcdef");
				input++;
				count++;
			}
			if (*input == 'd')
			{
				integer = va_arg(args, int);
				ft_putnbr(integer);
				input++;
				count++;
			}
			if (*input == 'i')
			{
				integer = va_arg(args, int);
				ft_putnbr(integer);
				input++;
				count++;
			}
			if (*input == 'u')
			{
				numunsigned = va_arg(args, int);
				ft_putnbr_base(numunsigned, "0123456789");
				input++;
				count++;
			}
			if (*input == 'x')
			{
				numunsigned = va_arg(args, int);
				ft_putnbr_base(numunsigned, "0123456789abcdef");
				input++;
				count++;
			}
			if (*input == 'X')
			{
				numunsigned = va_arg(args, int);
				ft_putnbr_base(numunsigned, "0123456789ABCDEF");
				input++;
				count++;
			}
			if (*input == '%')
			{
				ft_putchar('%');
				input++;
				count++;
			}
		}
		else
		{
			ft_putchar(*input);
			input++;
			count++;
		}
	}
	return (count);
}
int	ft_printf(const char *input, ...)
{
	va_list args;
	int count;
	va_start(args, input);
	count = ft_conversion(input, args);
	va_end(args);

	return (count);
}
