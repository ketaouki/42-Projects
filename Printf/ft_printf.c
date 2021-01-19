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


void	ft_initialise_structure(t_input	*flag)
{
	flag->flag_less = 0;
	flag->flag_zero = 0;
	flag->flag_dot = 0;
	flag->flag_star = 0;
	flag->largeur = 0;
	flag->precision = 0;
}

void	ft_flag_structure(t_input *flag, const char **input, va_list args)
{
	if (**input >= '1' || **input <= '9')
	{
		flag->largeur = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == '-')
	{
		flag->flag_less = 1;
		(*input)++;
		flag->largeur = 1;
		if (**input >= '0' || **input <= '9')
			flag->largeur = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == '0')
	{
		flag->flag_zero = 1;
		(*input)++;
		flag->largeur = 1;
		if (**input >= '0' || **input <= '9')
			flag->largeur = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == '*')
	{
		flag->flag_star = 1;
		(*input)++;
		flag->largeur = 1;
		if (**input >= '0' || **input <= '9')
			flag->largeur = va_arg(args, int);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if(**input == '.')
	{
		flag->flag_dot = 1;
		(*input)++;
		flag->precision = 1;
		if (**input >= '0' || **input <= '9')
			flag->precision = ft_atoi(*input);
		while (**input >= '0' && **input <= '9')
			(*input)++;
	}
	if (**input == 'c' || **input == 's' || **input == 'p' ||
			**input == 'd' || **input == 'i' || **input == 'u' ||
			**input == 'x' || **input == 'X' || **input == '%')
	{
		flag->type = **input;
		(*input)++;
	}
}

int	lecture_chaine(const char *input, va_list args, va_list copy)
{
	int	nb_caractere_imprime;
	t_input flag;

	nb_caractere_imprime = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			ft_initialise_structure(&flag);
			ft_flag_structure(&flag, &input, args);
			printf("flag zero = %d\n", flag.flag_zero);
			printf("flag less = %d\n", flag.flag_less);
			printf("largeur = %d\n", flag.largeur);
			printf("flag dot = %d\n", flag.flag_dot);
			printf("precision = %d\n", flag.precision);
			printf("type = %c\n", flag.type);
			//nb_caractere_imprime += ft_conversion(&input, args, copy);
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
