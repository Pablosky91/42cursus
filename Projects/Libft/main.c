/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:38:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/12 12:56:21 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	test_same_result(char *name, int (*mine)(int), int (*real)(int))
{
	int	aux;
	int	my_sol;
	int	sol;

	printf("\n\t%s\n\n", name);
	aux = 0;
	while (aux < 200)
	{
		sol = real(aux);
		my_sol = mine(aux);
		printf("%3d: %d %d -> ", aux, sol, my_sol);
		if (sol == my_sol)
			printf("igual\n");
		else
			printf("DESIGUAL\n");
		aux++;
	}
}

int	main(void)
{
	test_same_result("ISALPHA", isalpha, ft_isalpha);
	test_same_result("ISDIGIT", isdigit, ft_isdigit);
	test_same_result("ISALNUM", isalnum, ft_isalnum);
	test_same_result("ISASCII", isdigit, ft_isascii);
	test_same_result("ISPRINT", isdigit, ft_isprint);
	return (0);
}
