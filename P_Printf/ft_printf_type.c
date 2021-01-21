#include "ft_printf.h"

int	ft_type(s_input *s, va_list args)
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
		s->type = va_arg(args, int);
		ft_putchar(s->type);
		nb_caractere_imprime++;
		s->type = '\0';
	}
	if (s->type == 's')
	{
		str = va_arg(args, char *);
		nb_caractere_imprime += ft_putstr(str);
		s->type = '\0';
	}
	if(s->type == 'p')
	{
		str = va_arg(args, void *);
		ft_putstr("0x");
		nb_caractere_imprime += 2;
		nb_caractere_imprime += ft_putadress_hexa(str, "0123456789abcdef");
		s->type = '\0';
	}
	if (s->type == 'd')
	{
		integer = va_arg(args, int);
		if (s->f_dot == 1 && integer < 0)
		{
			integer = integer * -1;
			ft_putchar('0');
			nb_caractere_imprime += 2; // Pour le moins que je rqjoute dans la fonction count
		}
		nb_caractere_imprime += ft_putnbr(integer);
		s->type = '\0';
	}
	if (s->type == 'i')
	{
		integer = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr(integer);
		s->type = '\0';
	}
	if (s->type == 'u')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789");
		s->type = '\0';
	}
	if (s->type == 'x')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789abcdef");
		s->type = '\0';
	}
	if (s->type == 'X')
	{
		numunsigned = va_arg(args, int);
		nb_caractere_imprime += ft_putnbr_base(numunsigned, "0123456789ABCDEF");
		s->type = '\0';
	}
	if (s->type == '%')
	{
		ft_putchar('%');
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}
