/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdel-olm <pdel-olm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:45:17 by pdel-olm          #+#    #+#             */
/*   Updated: 2024/02/01 18:01:31 by pdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		copy_words(char **words, char const *s, char c);
static size_t	count_words(char const *s, char c);

/*
Allocates (with malloc(3)) and returns an array of strings obtained
	by splitting ’s’ using the character ’c’ as a delimiter.
The array must end with a NULL pointer.
*/
char	**ft_split(char const *s, char c)
{
	char	**words;

	words = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!words)
		return (0);
	copy_words(words, s, c);
	return (words);
}

static void	copy_words(char **words, char const *s, char c)
{
	size_t	start_word;
	size_t	word_len;
	size_t	i;
	size_t	num_word;	

	start_word = 0;
	word_len = 0;
	i = 0;
	num_word = 0;
	while (i <= ft_strlen(s))
	{
		if ((s[i] == c || s[i] == '\0') && word_len != 0)
		{
			words[num_word] = ft_substr(s, start_word, word_len);
			word_len = 0;
			num_word++;
		}
		else if (s[i] != c)
		{
			if (word_len == 0)
				start_word = i;
			word_len++;
		}
		i++;
	}
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
