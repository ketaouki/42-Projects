/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:20:44 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/21 08:49:42 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int d = 5;
	// ft_printf("%2d", d);
	// printf("\n");
	// printf("%2d", d);
	printf(" %d ", ft_printf(" %.d ", 0));
	printf("\n");
	printf(" %d ", printf(" %.d ", 0));
	printf("\n");
}


/* DONT WORK

"%1.d", 0
"%.0d", 0
" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1
" 0*%-0*.10d*0 0*%-0*.0d*0 ", 21, 1021, 21, -1011
" 0*%0-*d*0 0*%0*d*0 ", 21, 1021, 21, -1011
" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101
" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101
" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101
" *%-*.*d* *%*.*d* ", 4, 5, 10, 10, 21, -10
" %-3.2d %10.42d ", 10, -10
" %-3.2d %10.42d ", 1, -1
" %.d ", 0


 but WILL WORK */
