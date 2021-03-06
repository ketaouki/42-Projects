#include "ft_printf.h"

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &d, 1);
}

int		ft_putnbr(int n)
{
	long nb;
	int nb_caractere_imprime;

	nb = (long)n;
	nb_caractere_imprime = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		nb_caractere_imprime++;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb_caractere_imprime++;
	}
	ft_putchar((nb % 10) + '0');
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}

int		ft_putstr(char *str)
{
	int	i;
	int nb_caractere_imprime;

	i = 0;
	nb_caractere_imprime = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
			nb_caractere_imprime++;
		}
	}
	return (nb_caractere_imprime);
}

int		ft_putnbr_base(unsigned int nbr, char *base)
{
	int				i;
	unsigned int	k;
	unsigned int	nb;
	int nb_caractere_imprime;

	i = 0;
	nb = nbr;
	k = ft_strlen(base);
	nb_caractere_imprime = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		nb_caractere_imprime++;
	}
	if (nb >= k)
	{
		ft_putnbr_base((nb / k), base);
		nb_caractere_imprime++;
	}
	ft_putchar(base[nb % k]);
	nb_caractere_imprime++;
	return (nb_caractere_imprime);
}


int		ft_putadress_hexa(void *str, char *base)
{
	char			dest[9];
	int				i;
	unsigned long	nb;
	int nb_caractere_imprime;

	nb = (unsigned long)str;
	i = 8;
	nb_caractere_imprime = 0;
	while ((nb / ft_strlen(base) > 0))
	{
		dest[i] = base[((nb % ft_strlen(base)))];
		nb = nb / ft_strlen(base);
		i--;
	}
	dest[i] = base[((nb % 10))];
	while (i < 9)
	{
		ft_putchar(dest[i]);
		i++;
		nb_caractere_imprime++;
	}
	return (nb_caractere_imprime);
}
