#include "ft_printf.h"

void	ft_putchar(char c)
{
	unsigned char	d;

	d = (unsigned char)c;
	write(1, &d, 1);
}

int		ft_strlen( char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

void	ft_putnbr(int n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				i;
	unsigned int	k;
	unsigned int	nb;

	i = 0;
	nb = nbr;
	k = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= k)
	{
		ft_putnbr_base((nb / k), base);
	}
	ft_putchar(base[nb % k]);
}

void	ft_putadress_hexa(void *str, char *base)
{
	char			dest[9];
	int				i;
	unsigned long	nb;

	nb = (unsigned long)str;
	i = 8;
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
	}
}

static int	ft_over(int n)
{
	if (n < 0)
		return (0);
	return (-1);
}

int			ft_atoi(const char *str)
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
		if (res < 0)
			return (ft_over(n));
	}
	res = res * n;
	return (res);
}
