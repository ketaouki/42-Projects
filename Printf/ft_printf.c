#include "ft_printf.h"

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &d, 1);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	res;

	i = 0;
	n = 1;
	res = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10;
		res = res + (str[i] - '0');
		i++;
	}
	res = res * n;
	return (res);
}


void	ft_initialise_structure(t_input	*s)
{
	s->s_less = 0;
	s->s_zero = 0;
	s->s_dot = 0;
	s->s_star = 0;
	s->width = 0;
	s->precision = 0;
	s->index = 0;
}

void	ft_s_structure(t_input *s, const char **input, va_list args)
{
	if (**input >= '1' || **input <= '9')
	{
		s->width = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == '-')
	{
		s->s_less = 1;
		(*input)++;
		s->width = 1;
		if (**input >= '0' || **input <= '9')
			s->width = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == '0')
	{
		s->s_zero = 1;
		(*input)++;
		s->width = 1;
		if (**input >= '0' || **input <= '9')
			s->width = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == '*')
	{
		s->s_star = 1;
		(*input)++;
		s->width = 1;
		if (**input >= '0' || **input <= '9')
			s->width = va_arg(args, int);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if(**input == '.')
	{
		s->s_dot = 1;
		(*input)++;
		s->precision = 1;
		if (**input >= '0' || **input <= '9')
			s->precision = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == 'c' || **input == 's' || **input == 'p' ||
			**input == 'd' || **input == 'i' || **input == 'u' ||
			**input == 'x' || **input == 'X' || **input == '%')
	{
		s->type = **input;
		(*input)++;
	}
}

int	lecture_chaine(const char *input, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	t_input s;

	ft_initialise_structure(&s);
	nb_caractere_imprime = 0;
	while (input[s.index])
	{
		if (input[s.index] == '%')
		{
			s.index++;
			ft_initialise_structure(&s);
			ft_s_structure(&s, &input, args);
			//nb_caractere_imprime += ft_conversion(&input, args, copy);
		}
		else
		{
			ft_putchar(input[s.index]);
			s.index++;
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
