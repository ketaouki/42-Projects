#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *input, ...);
int		lecture_chaine(const char *input, va_list args, va_list copy);
int		ft_conversion(const char **input, va_list args, va_list copy);
int		ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putadress_hexa(void *str, char *base);
int		ft_strlen( char *str);
int		ft_type(const char ***input, va_list args);

int	ft_type_count(const char ***input, va_list args);

#endif
