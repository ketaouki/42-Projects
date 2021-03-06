#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct	s_input
{
	int		f_less;
	int		f_zero;
	int		f_dot;
	int		width;
	int		precision;
	int		index;

	int		nbr_char_a_imprime;
	int		negatif;
	int		width_supp_precision;
	char	type;
}				s_input;

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
int		ft_putstr(s_input *s, char *str);
int		ft_putadress_hexa(void *str, char *base);
int		ft_putnbr(s_input *s, int n);
int		ft_putneg(void);
int		ft_putnbr_unsigned(s_input *s, unsigned int n);
int		ft_putnbr_base(s_input *s, unsigned int nbr, char *base);


int		ft_type(s_input *s, va_list args);
int		ft_char_type(s_input *s, va_list args);
int		ft_str_p_type(s_input *s, va_list args);
int		ft_d_i_type(s_input *s, va_list args);
int		ft_u_x_type(s_input *s, va_list args);


//		COUNT_FONCTINS		//

void	ft_char_type_count(s_input *s, va_list copy);
int		ft_putstr_count(s_input *s, char *str);
int		ft_putadress_hexa_count(void *str, char *base);
int		ft_putnbr_count(s_input *s, int n);
int		ft_putnbr_count_unsigned(s_input *s, unsigned int n);
int		ft_putnbr_base_count(s_input *s, unsigned int nbr, char *base);


void	ft_type_count(s_input *s, va_list copy);
void	ft_str_p_type_count(s_input *s, va_list args);
void	ft_d_i_type_count(s_input *s, va_list copy);
void	ft_u_x_type_count(s_input *s, va_list copy);
//		GESTION_FLAG		//


int		ft_width_supp_precision(s_input *s, va_list args);
int		ft_less_dot(s_input *s, va_list args);
int		ft_zero_only(s_input *s, va_list args);
int		ft_dot_only(s_input *s, va_list args);
int		ft_less_only(s_input *s, va_list args);
int		gestion_flag(s_input *s, va_list args);

//					//


//					//

int		ft_print(s_input *s, va_list args);
int		read_input(const char *input, va_list args, s_input *s, va_list copy);
int		ft_printf(const char *input, ...);

#endif
