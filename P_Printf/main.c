/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:15:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/01 14:32:07 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	// printf(" %d ", ft_printf("%010.0d", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", printf("%010.0d", UINT_MAX + 1));
	// printf("\n");

	// printf("\n TEST\n");
	// printf(" %d ", printf("%05.3d", 10));
	// printf("\n");

	// printf("\n TEST 1\n");
	// printf(" %d ", ft_printf(" %p ", -1));
	// printf("\n");
	// printf(" %d ", printf(" %p ", -1));

	//printf("\n TEST 9\n");
	//printf(" %d ", ft_printf(" *%-*.*u* *%*.*u* ", 6, 2, 102, 10, 21, -101));
	//printf("\n");
	//printf(" %d ", printf(" *%-*.*u* *%*.*u* ", 6, 2, 102, 10, 21, -101));

	// printf("\n TEST 13\n");

	// printf(" %d ", ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101));
	// printf("\n");
	// printf(" %d ", printf(" 0*%0-*.*u*0 0*%0*.*u*0 ", 2, 6, 102, 21, 10, -101));

	// printf("\n TEST 18\n");

	// printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	// printf("\n");
	// printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));


	 printf("\n TEST 72\n");
printf("UINT MAX %d\n", UINT_MAX);

	 printf(" %d ", printf("%9.0u", -1));
	 printf("\n");
	 printf(" %d ", ft_printf("%9.0u", -1));

	// printf("\n TEST 24\n");
	// printf(" %d ", printf("%9.10u", UINT_MAX));
	// printf("\n");
	// printf(" %d ", ft_printf("%9.10u", UINT_MAX));

	// printf("\n TEST 69\n");
	// printf(" %d ", printf("%.0d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%.0d", 0));

	// printf("\n TEST 72\n");
	// printf(" %d ", printf("%1.d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%1.d", 0));

	// printf("\n TEST 73\n");
	// printf(" %d ", printf("%2.d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%2.d", 0));

	// printf("\n TEST 74\n");
	// printf(" %d ", printf("%3.d", 0));
	// printf("\n");
	// printf(" %d ", ft_printf("%3.d", 0));

	return (0);
}
