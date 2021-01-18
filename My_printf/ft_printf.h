/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:13:19 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/15 11:26:50 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

//		STRUCUTRE		//

typedef	struct s_input
{
	int	taille;
	int	largeur;
}	t_input;



//		FT_PRINTF_UTILS	//

int		ft_strlen(char *str);
int		ft_atoi(const char *str);

//		FT_PRINTF_PUT	//

void	ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putadress_hexa(void *str, char *base);

//		FT_PRINTF_COUNT	//

int		ft_putnbr_count(int n);
int		ft_putstr_count(char *str);
int		ft_putnbr_base_count(unsigned int nbr, char *base);
int		ft_putadress_hexa_count(void *str, char *base);
int		ft_type_count(const char ***input, va_list copy);

//		FT_PRINTF_TYPE	//

int	ft_type(const char ***input, va_list args);

//		FT_PRINTF		//

int		ft_printf(const char *input, ...);

#endif
