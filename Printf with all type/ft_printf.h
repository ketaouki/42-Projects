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

//		UTILS_FONCTIONS		//

int		ft_atoi(const char *str);
int		ft_strlen(char *str);

//		STRUCTURE_FONCTIONS		//

void	ft_initialise_structure(s_input	*s);
void	ft_width(s_input *s, const char *input);
void	ft_precision(s_input *s, const char *input);
void	ft_star(s_input *s, const char *input, va_list args, va_list copy);
void	ft_less_or_zero(s_input *s, const char *input);
void	ft_dot(s_input *s, const char *input, va_list args, va_list copy);
void	ft_add_in_structure(s_input *s, const char *input, va_list args, va_list copy);

//		PUT_FONCTIONS		//

void	ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putadress_hexa(void *str, char *base);

int		ft_type(s_input *s, va_list args);
int		ft_char_type(s_input *s, va_list args);
int		ft_str_p_type(s_input *s, va_list args);
int		ft_d_i_type(s_input *s, va_list args);
int		ft_u_x_type(s_input *s, va_list args);


//		COUNT_FONCTINS		//

int		ft_putnbr_count(int n);
int		ft_putstr_count(char *str);
int		ft_putnbr_base_count(unsigned int nbr, char *base);
int		ft_putadress_hexa_count(void *str, char *base);

int		ft_type_count(s_input *s, va_list copy);
int		ft_char_type_count(va_list copy);
int		ft_str_p_type_count(s_input *s, va_list copy);
int		ft_d_i_type_count(va_list copy);
int		ft_u_x_type_count(s_input *s, va_list copy);

//					//

int		ft_print(s_input *s, va_list args, va_list copy);
int		read_input(const char *input, va_list args, s_input *s, va_list copy);
int		ft_printf(const char *input, ...);

#endif
