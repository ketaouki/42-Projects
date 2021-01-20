/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:13:19 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/20 08:25:39 by ketaouki         ###   ########lyon.fr   */
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
	int		s_less;
	int		s_zero;
	int		s_dot;
	int		s_star;
	int		width;
	int		precision;
	int		index;
	char	type;

}	t_input;



//		FT_PRINTF_UTILS	//



//		FT_PRINTF_PUT	//


//		FT_PRINTF_COUNT	//


//		FT_PRINTF_TYPE	//


//		FT_PRINTF		//

int		ft_printf(const char *input, ...);

#endif
