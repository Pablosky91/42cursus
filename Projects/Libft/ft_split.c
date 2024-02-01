/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/01 15:23:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);

/*
Allocates (with malloc(3)) and returns an array of strings obtained
	by splitting ’s’ using the character ’c’ as a delimiter.
The array must end with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	printf("Frase: _%s_\nSeparador: _%c_\nPalabras: %zu", s, c, count_words(s, c));
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		is_start_word;
	size_t	i;

	count = 0;
	is_start_word = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && !is_start_word)
			is_start_word = 1;
		else if (s[i] != c && is_start_word)
		{
			is_start_word = 0;
			count++;
		}
		i++;
	}
	return (count);
}
