/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:38:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/01/25 18:49:44 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>

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
	/*char	text1[50] = "This is a standart text";;
	char	empty[50] = "";
	test_same_result("ISALPHA", isalpha, ft_isalpha);
	test_same_result("ISDIGIT", isdigit, ft_isdigit);
	test_same_result("ISALNUM", isalnum, ft_isalnum);
	test_same_result("ISASCII", isascii, ft_isascii);
	test_same_result("ISPRINT", isprint, ft_isprint);
	printf("\n\tLEN\n\n%s-> %zu\n%s-> %zu\n",
		text1, ft_strlen(text1), empty, ft_strlen(empty));
	printf("\n\tMEMSET\n\n%s -> ", text1);
	printf("%s\n%s -> ", ft_memset(text1, '_', 4), empty);
	printf("%s\n", ft_memset(empty, '_', 4));*/
/*	char	string[] = "Hello";
	char	buffer1[50] = "Previous";
	char	buffer2[50] = "Previous";
	size_t	size = 0;

	size_t r1 = strlcpy(buffer1, string, size);
	size_t r2 = ft_strlcpy(buffer2, string, size);
	printf("Copied '%s' into '%s', length %zu\n", string, buffer1, r1);
	printf("Copied '%s' into '%s', length %zu\n", string, buffer2, r2);*/
	
/*	char	string[] = "Hello";
	char	buffer1[50] = "Previous";
	char	buffer2[50] = "Previous";
	size_t	size = 13;
	size_t r1 = strlcat(buffer1, string, size);
	size_t r2 = ft_strlcat(buffer2, string, size);
	printf("Copied '%s' into '%s', length %zu\n", string, buffer1, r1);
	printf("Copied '%s' into '%s', length %zu\n", string, buffer2, r2);*/
	
	//printf("Original -> .%s.\n", strchr("teste", 'e'));
	//printf("Mia -> .%s.\n", ft_strchr("teste", 'e'));

	char	s1[50] = "Hel\200\200o";
	char	s2[50] = "Hel\200\222o World";
	int		size = 6;

	printf("Original -> %d\n", strncmp(s1, s2, size));
	printf("Mia -> %d\n", ft_strncmp(s1, s2, size));
	return (0);
}
