/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:15:21 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/26 13:55:46 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	//printf(" %d ", ft_printf("%4.2d",  101));
	//printf("\n");
	//printf(" %d ", printf("%4.2d",  101));
	//printf("\n");

	printf("\n TEST 16\n");
	printf(" %d ", printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1));
	printf("\n");
	printf(" %d ", ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- ", -2, 0, 21, 1));
	printf("\n TEST 17\n");
	printf(" %d ", printf("%0*.10d", 21, INT_MIN));
	printf("\n");
	printf(" %d ", ft_printf("%0*.10d", 21, INT_MIN));
	printf("\n TEST 57\n");
	printf(" %d ", printf("%09.0d", UINT_MAX + 1));
	printf("\n");
	printf(" %d ", ft_printf("%09.0d", UINT_MAX + 1));




	return (0);
}
