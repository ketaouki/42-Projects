#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *input, ...);
void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_putadress_hexa(void *str, char *base);



#endif
