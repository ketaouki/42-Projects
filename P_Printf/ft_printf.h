#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_input
{
	int		f_less;
	int		f_zero;
	int		f_dot;
	int		f_star;
	int		width;
	int		precision;
	int		index;
	char	type;
}	s_input;

//		STRUCTURE_FONCTIONS		//

void	ft_initialise_structure(s_input	*s);
void	ft_width(s_input *s, const char *input);
void	ft_precision(s_input *s, const char *input);
void	ft_star(s_input *s, const char *input, va_list args);
void	ft_less_or_zero(s_input *s, const char *input);
void	ft_dot(s_input *s, const char *input, va_list args);
void	ft_add_in_structure(s_input *s, const char *input, va_list args);


//		PUT_FONCTIONS		//

void	ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putadress_hexa(void *str, char *base);
int		ft_type(s_input *s, const char *input, va_list args);

//		COUNT_FONCTINS		//

int		ft_type_count(s_input *s, const char *input, va_list copy);

//		UTILS_FONCTIONS		//

int		ft_atoi(const char *str);
int		ft_strlen(char *str);

//					//

int		ft_print(s_input *s, const char *input, va_list args, va_list copy);
int		read_input(const char *input, va_list args, s_input *s, va_list copy);
int		ft_printf(const char *input, ...);

#endif
