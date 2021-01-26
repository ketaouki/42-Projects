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

	//printf("\n TEST 2\n");
	//printf(" %d ", printf(" %.d ", 0));
	//printf("\n");
	//printf(" %d ", ft_printf(" %.d ", 0));

	//printf("\n TEST 57\n");
	//printf(" %d ", printf("%09.0d", UINT_MAX + 1));
	//printf("\n");
	//printf(" %d ", ft_printf("%09.0d", UINT_MAX + 1));

	printf("\n TEST 72\n");
	printf(" %d ", printf(" %10.d", 0));
	printf("\n");
	printf(" %d ", ft_printf(" %10.d", 0));



	return (0);
}
