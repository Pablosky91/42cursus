/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:38:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/16 19:14:23 by pdel-olm         ###   ########.fr       */
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
	if (ok)
		printf("Everyhing matches up.\n");
}

int	main(void)
{
	char	text1[50] = "This is a standart text";;
	char	empty[50] = "";
	test_same_result("ISALPHA", isalpha, ft_isalpha);
	test_same_result("ISDIGIT", isdigit, ft_isdigit);
	test_same_result("ISALNUM", isalnum, ft_isalnum);
	test_same_result("ISASCII", isascii, ft_isascii);
	test_same_result("ISPRINT", isprint, ft_isprint);
	printf("\n\tLEN\n\n%s: %zu\n%s: %zu\n",
		text1, ft_strlen(text1), empty, ft_strlen(empty));
	printf("\n\tMEMSET\n\n%s -> ", text1);
	printf("%s\n%s -> ", ft_memset(text1, '_', 4), empty);
	printf("%s\n", ft_memset(empty, '_', 4));
	return (0);
}
