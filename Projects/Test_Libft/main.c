/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:38:33 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/12 19:51:18 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

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
	test_same_result("ISALPHA", isalpha, ft_isalpha);
	test_same_result("ISDIGIT", isdigit, ft_isdigit);
	test_same_result("ISALNUM", isalnum, ft_isalnum);
	test_same_result("ISASCII", isascii, ft_isascii);
	test_same_result("ISPRINT", isprint, ft_isprint);
	/*char	text1[50] = "This is a standart text";;
	char	empty[50] = "";
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

	// char	s1[50] = "Hel\200\200o";
	// char	s2[50] = "Hel\200\222o World";
	// int		size = 6;

	// printf("Original -> %d\n", strncmp(s1, s2, size));
	// printf("Mia -> %d\n", ft_strncmp(s1, s2, size));

	// char	s1[50] = "";
	// char	s2[50] = "a";
	// int		size = 1;

	// printf("Original -> %s\n", strnstr(s1, s2, size));
	// printf("   Mia   -> %s\n", ft_strnstr(s1, s2, size));
	
	// char n[] = "  -123456789123";
	// printf("Original -> %d\n", atoi(n));
	// printf("   Mia   -> %d\n", ft_atoi(n));
	
	/*char sub[] = "asd";
	int start = 2;
	int len = 0;
	//printf("Original -> .%s.\n", substr(sub, start, len));
	printf("   Mia   -> .%s.\n", ft_substr(sub, start, len));
	*/
	/*char *trim = 0;
	char *set = " \n\t";
	printf("Word: _%s_, Set: _%s_\nTrim:_%s_", trim, set, ft_strtrim(trim, set));*/

	//printf("Frase: _%s_\nSeparador: _%c_\nPalabras: %zu", s, c, count_words(s, c));
	/*char **words = ft_split("\t\t\t\thello!\t\t\t\t", 9);
	int i = 0;
	printf("Split:\n");
	while (words[i])
	{
		printf("_%s_\n", words[i]);
		i++;
	}*/

	//printf("%s", ft_itoa(0));
	return (0);
}
