/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:15:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/02/04 09:09:17 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("\n TEST 16\n");
	printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));
	 printf("\n");
	printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));

 	// printf("\n TEST 25\n");
	// printf(" %d ", ft_printf("%10.0u", UINT_MAX));
	//  printf("\n");
	// printf(" %d ", printf("%10.0u", UINT_MAX));

	printf("\n TEST 57\n");
	printf(" %d ", ft_printf("%09.0u", UINT_MAX + 1));
	printf("\n");
	printf(" %d ", printf("%09.0u", UINT_MAX + 1));

	printf("\n TEST 21\n");

	printf(" %d ", ft_printf("%9.0u", UINT_MAX));
	printf("\n");
	printf(" %d ", printf("%9.0u", UINT_MAX));

	printf("\n TEST 59\n");

	printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	printf("\n");
	printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));

	// printf("\n TEST 13\n");

	// printf(" %d ", ft_printf("%1.u", 0));
	// printf("\n");
	// printf(" %d ", printf("%1.u", 0));



	// printf("\n TEST 16\n");
	// printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));
	// printf("\n");
	// printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -2, 0, 21, 1));

	// printf("\n TEST 18\n");
	// printf(" %d ", printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));
	// printf("\n");
	// printf(" %d ", ft_printf(" --0*%0*.0u*0 0*%0*.10u*0-- ", -21, LONG_MAX, 21, LONG_MIN));

	// printf("\n TEST 57\n");
	// printf(" %d ", printf("%09.0u", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%09.0u", UINT_MAX + 1));

	// printf("\n TEST 59\n");
	// printf(" %d ", printf("%09.2u", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%09.2u", UINT_MAX + 1));

	// printf("\n TEST 67\n");
	// printf(" %d ", printf("%011.2u", UINT_MAX + 1));
	// printf("\n");
	// printf(" %d ", ft_printf("%011.2u", UINT_MAX + 1));

	return (0);
}
