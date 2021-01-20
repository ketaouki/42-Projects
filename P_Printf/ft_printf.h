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

//		STRUCTURE		//

void	ft_initialise_structure(s_input	*s);
void	ft_width(s_input *s, const char *input);
void	ft_precision(s_input *s, const char *input);
void	ft_star(s_input *s, const char *input, va_list args);
void	ft_less_or_zero(s_input *s, const char *input);
void	ft_dot(s_input *s, const char *input, va_list args);
void	ft_add_in_structure(s_input *s, const char *input, va_list args);

//		UTILS		//

int		ft_atoi(const char *str);
void	ft_putchar(char c);

//					//

int		ft_printf(const char *input, ...);

#endif
