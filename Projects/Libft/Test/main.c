/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:38:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/16 16:57:42 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

void	test_same_result(char *name, int (*mine)(int), int (*real)(int))
{
	int	aux;
	int	my_sol;
	int	sol;
	int	ok;

	printf("\n\t%s\n\n", name);
	aux = 0;
	ok = 1;
	while (aux <= 127)
	{
		sol = real(aux);
		my_sol = mine(aux);
		if (sol != my_sol)
		{
			printf("Value %3d: %d, %d -> DESIGUAL\n", aux, sol, my_sol);
			ok = 0;
		}
		aux++;
	}
	if (ok == 1)
		printf("Everyhing matches up.\n");
}

int	main(void)
{
	test_same_result("ISALPHA", isalpha, ft_isalpha);
	test_same_result("ISDIGIT", isdigit, ft_isdigit);
	test_same_result("ISALNUM", isalnum, ft_isalpha);
	test_same_result("ISASCII", isascii, ft_isascii);
	test_same_result("ISPRINT", isprint, ft_isprint);
	printf("\nLEN: %zu\n", ft_strlen("12345"));
	return (0);
}
