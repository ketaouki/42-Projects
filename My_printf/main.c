/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketaouki <ketaouki@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:15:17 by ketaouki          #+#    #+#             */
/*   Updated: 2021/01/18 09:57:38 by ketaouki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char d;

	d = 20;
	printf("%d", ft_printf(" %-3.2d %10.42d ", d, d));
	printf("\n");
	printf("%d",  printf(" %-3.2d %10.42d ", d, d));
	printf("\n");
	return (0);
}
